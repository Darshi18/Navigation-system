#include "multi_map_nav/multi_map_navigator.hpp"
#include <chrono>
#include <thread>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include "ament_index_cpp/get_package_share_directory.hpp"

#include <nav2_msgs/srv/load_map.hpp>

using namespace std::chrono_literals;
using MultiMapNavigate = multi_map_nav_interfaces::action::MultiMapNavigate;

MultiMapNavigator::MultiMapNavigator()
: Node("multi_map_navigator")
{
  // Create action client for sending navigation goals
  //nav_client_ = rclcpp_action::create_client<MultiMapNavigate>(this, "multi_map_navigator");
  nav_client_ = rclcpp_action::create_client<nav2_msgs::action::NavigateToPose>(this, "navigate_to_pose");


  // Create action server for handling incoming navigation requests
  action_server_ = rclcpp_action::create_server<MultiMapNavigate>(
    this,
    "multi_map_navigator",
    std::bind(&MultiMapNavigator::handle_goal, this, std::placeholders::_1, std::placeholders::_2),
    std::bind(&MultiMapNavigator::handle_cancel, this, std::placeholders::_1),
    std::bind(&MultiMapNavigator::handle_accepted, this, std::placeholders::_1)
  );

  // Publisher to reset AMCL
  initialpose_pub_ = this->create_publisher<geometry_msgs::msg::PoseWithCovarianceStamped>("/initialpose", 10);
  amcl_pose_sub_ = this->create_subscription<geometry_msgs::msg::PoseWithCovarianceStamped>(
    "/amcl_pose", 10,
    std::bind(&MultiMapNavigator::amcl_pose_callback, this, std::placeholders::_1));


  // Open SQLite DB
  int rc = sqlite3_open("wormholes.db", &db_);
  if (rc) {
    RCLCPP_ERROR(this->get_logger(), "Failed to open database: %s", sqlite3_errmsg(db_));
    db_ = nullptr;
  } else {
    RCLCPP_INFO(this->get_logger(), "Database opened successfully.");
  }

  // Set initial map name
  current_map_ = "room1";  // Set this according to your starting map
  map_load_client_ = this->create_client<nav2_msgs::srv::LoadMap>("/map_server/load_map");
}

MultiMapNavigator::~MultiMapNavigator()
{
  if (db_) {
    sqlite3_close(db_);
  }
}

void MultiMapNavigator::send_goal(double x, double y, double theta, const std::string & target_map)
{
  switch_map(target_map);
  using NavigateToPose = nav2_msgs::action::NavigateToPose;

  auto nav_client = rclcpp_action::create_client<NavigateToPose>(this, "navigate_to_pose");

  //if (!navigate_to_pose_client->wait_for_action_server(5s)) {
  if (!nav_client_->wait_for_action_server(std::chrono::seconds(5))) {

    RCLCPP_ERROR(this->get_logger(), "Navigation action server not available");
    return;
  }

  NavigateToPose::Goal goal_msg;
  goal_msg.pose.header.frame_id = "map";
  goal_msg.pose.header.stamp = this->now();
  goal_msg.pose.pose.position.x = x;
  goal_msg.pose.pose.position.y = y;

  tf2::Quaternion q;
  q.setRPY(0, 0, theta);
  goal_msg.pose.pose.orientation = tf2::toMsg(q);

  auto send_goal_options = rclcpp_action::Client<NavigateToPose>::SendGoalOptions();
  send_goal_options.feedback_callback = [this](auto, const auto & feedback) {
    RCLCPP_INFO(this->get_logger(), "NavigateToPose Feedback: %.2f, %.2f",
                feedback->current_pose.pose.position.x,
                feedback->current_pose.pose.position.y);
  };

  auto goal_handle_future = nav_client->async_send_goal(goal_msg, send_goal_options);
  rclcpp::executors::SingleThreadedExecutor exec;
  exec.add_node(shared_from_this());

 if (exec.spin_until_future_complete(goal_handle_future, 30s) != rclcpp::FutureReturnCode::SUCCESS ||
    !goal_handle_future.get())
 {
  RCLCPP_ERROR(this->get_logger(), "Failed to send goal");
  return;
 }

  auto result_future = nav_client->async_get_result(goal_handle_future.get());
  if (rclcpp::spin_until_future_complete(this->get_node_base_interface(), result_future, 60s) !=
      rclcpp::FutureReturnCode::SUCCESS) {
    RCLCPP_ERROR(this->get_logger(), "Navigation did not complete.");
    return;
  }

  auto result = result_future.get();
  if (result.code == rclcpp_action::ResultCode::SUCCEEDED) {
    RCLCPP_INFO(this->get_logger(), "Navigation succeeded.");
  } else {
    RCLCPP_ERROR(this->get_logger(), "Navigation failed.");
  }
}

void MultiMapNavigator::switch_map(const std::string & map_name)
{
  auto request = std::make_shared<nav2_msgs::srv::LoadMap::Request>();

  // Use absolute path to the map
  std::string base_path = "/home/dd/task/";  // <-- Set this to your actual map directory
  request->map_url = base_path + map_name + ".yaml";

  if (!map_load_client_->wait_for_service(5s)) {
    RCLCPP_ERROR(this->get_logger(), "Map load service not available");
    return;
  }

  auto future = map_load_client_->async_send_request(request);
  if (future.wait_for(std::chrono::seconds(5)) == std::future_status::ready) {
    auto response = future.get();
    RCLCPP_INFO(this->get_logger(), "Map switched to: %s", map_name.c_str());
    current_map_ = map_name;
    reset_amcl();
  } else {
    RCLCPP_ERROR(this->get_logger(), "Failed to switch map to: %s", map_name.c_str());
  }
}


/*void MultiMapNavigator::reset_amcl()
{
  RCLCPP_INFO(this->get_logger(), "Resetting AMCL via /initialpose...");
} */

void MultiMapNavigator::reset_amcl()
{
  /*geometry_msgs::msg::PoseWithCovarianceStamped init_pose = current_amcl_pose_;  // reuse or modify
  //init_pose.header.stamp = this->now();
  initial_pose.header.stamp = this->now() - rclcpp::Duration::from_seconds(0.1); 
  init_pose.header.frame_id = "map";*/
  geometry_msgs::msg::PoseWithCovarianceStamped initial_pose;
  initial_pose.header.stamp = this->now() - rclcpp::Duration::from_seconds(0.1);
  initial_pose.header.frame_id = "map";

  // Example: keep covariance the same, or manually reset if needed
  initialpose_pub_->publish(initial_pose);
  RCLCPP_INFO(this->get_logger(), "AMCL reset with pose: x=%.2f, y=%.2f",
              initial_pose.pose.pose.position.x, initial_pose.pose.pose.position.y);
}


std::pair<double, double> MultiMapNavigator::get_wormhole_position(const std::string & map_name, const std::string & to_map)
{
  double x = 0.0, y = 0.0;
  std::string sql = "SELECT to_pose_x, to_pose_y FROM wormholes WHERE from_map = ? AND to_map = ?";
  sqlite3_stmt * stmt;

  if (!db_) return {x, y};

  if (sqlite3_prepare_v2(db_, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
    sqlite3_bind_text(stmt, 1, map_name.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, to_map.c_str(), -1, SQLITE_TRANSIENT);

    if (sqlite3_step(stmt) == SQLITE_ROW) {
      x = sqlite3_column_double(stmt, 0); // to_pose_x
      y = sqlite3_column_double(stmt, 1); // to_pose_y
    }

    sqlite3_finalize(stmt);
  }

  return {x, y};
}

rclcpp_action::GoalResponse MultiMapNavigator::handle_goal(
  const rclcpp_action::GoalUUID &,
  std::shared_ptr<const MultiMapNavigate::Goal> goal)
{
  RCLCPP_INFO(this->get_logger(), "Received goal to (%.2f, %.2f) in map: %s", goal->x, goal->y, goal->target_map.c_str());
  return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
}


rclcpp_action::CancelResponse MultiMapNavigator::handle_cancel(
  const std::shared_ptr<rclcpp_action::ServerGoalHandle<MultiMapNavigate>>)
{
  RCLCPP_INFO(this->get_logger(), "Goal cancel requested.");
  return rclcpp_action::CancelResponse::ACCEPT;
}

void MultiMapNavigator::amcl_pose_callback(const geometry_msgs::msg::PoseWithCovarianceStamped::SharedPtr msg)
{
  current_amcl_pose_ = *msg;
  RCLCPP_DEBUG(this->get_logger(), "Updated AMCL pose: x=%.2f, y=%.2f",
               current_amcl_pose_.pose.pose.position.x,
               current_amcl_pose_.pose.pose.position.y);
}

void MultiMapNavigator::handle_accepted(
  const std::shared_ptr<rclcpp_action::ServerGoalHandle<MultiMapNavigate>> goal_handle)
{
  std::thread{std::bind(&MultiMapNavigator::execute_navigation, this, goal_handle)}.detach();
}

void MultiMapNavigator::execute_navigation(
  const std::shared_ptr<rclcpp_action::ServerGoalHandle<MultiMapNavigate>> goal_handle)
{
  const auto goal = goal_handle->get_goal();
  auto feedback = std::make_shared<MultiMapNavigate::Feedback>();
  auto result = std::make_shared<MultiMapNavigate::Result>();

  sqlite3_stmt *stmt;
  std::string sql = "SELECT from_pose_x, from_pose_y, from_theta, to_pose_x, to_pose_y, to_theta "
                    "FROM wormholes WHERE from_map = ? AND to_map = ?";
  double from_x = 0, from_y = 0, from_theta = 0, to_x = 0, to_y = 0, to_theta = 0;

  if (sqlite3_prepare_v2(db_, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
    sqlite3_bind_text(stmt, 1, current_map_.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, goal->target_map.c_str(), -1, SQLITE_TRANSIENT);

    if (sqlite3_step(stmt) == SQLITE_ROW) {
      from_x = sqlite3_column_double(stmt, 0);
      from_y = sqlite3_column_double(stmt, 1);
      from_theta = sqlite3_column_double(stmt, 2);
      to_x = sqlite3_column_double(stmt, 3);
      to_y = sqlite3_column_double(stmt, 4);
      to_theta = sqlite3_column_double(stmt, 5);
    } else {
      RCLCPP_ERROR(this->get_logger(), "No wormhole found for map transition.");
      result->success = false;
      goal_handle->abort(result);
      return;
    }
    sqlite3_finalize(stmt);
  } else {
    RCLCPP_ERROR(this->get_logger(), "Failed to prepare wormhole SQL.");
    result->success = false;
    goal_handle->abort(result);
    return;
  }

  feedback->current_status = "Navigating to wormhole entrance...";
  goal_handle->publish_feedback(feedback);

  send_goal(from_x, from_y, from_theta, goal->target_map);
  std::this_thread::sleep_for(5s);  // Simulate wait

  feedback->current_status = "Switching maps...";
  goal_handle->publish_feedback(feedback);

  switch_map(goal->target_map);
  std::this_thread::sleep_for(2s);

  geometry_msgs::msg::PoseWithCovarianceStamped pose;
  pose.header.stamp = this->now() - rclcpp::Duration::from_seconds(0.1);
  pose.header.frame_id = "map";
  pose.pose.pose.position.x = to_x;
  pose.pose.pose.position.y = to_y;

  tf2::Quaternion q;
  q.setRPY(0, 0, to_theta);
  pose.pose.pose.orientation = tf2::toMsg(q);

  pose.pose.covariance[0] = 0.5;
  pose.pose.covariance[7] = 0.5;
  pose.pose.covariance[35] = 0.1;

  initialpose_pub_->publish(pose);
  std::this_thread::sleep_for(2s);

  feedback->current_status = "Navigating to final goal...";
  goal_handle->publish_feedback(feedback);

  send_goal(goal->x, goal->y, goal->theta, goal->target_map);

  result->success = true;
  goal_handle->succeed(result);
}
22
