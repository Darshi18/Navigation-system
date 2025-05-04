#include "multi_map_nav/multi_map_navigator.hpp"
#include <chrono>
#include <thread>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>

#include <nav2_msgs/srv/load_map.hpp>

using namespace std::chrono_literals;
using MultiMapNavigate = multi_map_nav_interfaces::action::MultiMapNavigate;

MultiMapNavigator::MultiMapNavigator()
: Node("multi_map_navigator")
{
  // Create action client for sending navigation goals
  nav_client_ = rclcpp_action::create_client<MultiMapNavigate>(this, "multi_map_navigator");

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

  // Open SQLite DB
  int rc = sqlite3_open("wormholes.db", &db_);
  if (rc) {
    RCLCPP_ERROR(this->get_logger(), "Failed to open database: %s", sqlite3_errmsg(db_));
    db_ = nullptr;
  } else {
    RCLCPP_INFO(this->get_logger(), "Database opened successfully.");
  }

  // Set initial map name
  current_map_ = "map1";  // Set this according to your starting map
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
  if (!nav_client_->wait_for_action_server(5s)) {
    RCLCPP_ERROR(this->get_logger(), "Action server not available");
    return;
  }

  auto goal_msg = MultiMapNavigate::Goal();
  goal_msg.x = x;
  goal_msg.y = y;
  goal_msg.theta = theta;
  goal_msg.target_map = target_map;

  auto send_goal_options = rclcpp_action::Client<MultiMapNavigate>::SendGoalOptions();
  send_goal_options.feedback_callback = [this](auto, const auto & feedback) {
    RCLCPP_INFO(this->get_logger(), "Feedback: %s", feedback->current_status.c_str());
  };

  auto goal_handle_future = nav_client_->async_send_goal(goal_msg, send_goal_options);
  if (rclcpp::spin_until_future_complete(this->get_node_base_interface(), goal_handle_future, 30s) !=
      rclcpp::FutureReturnCode::SUCCESS || !goal_handle_future.get()) {
    RCLCPP_ERROR(this->get_logger(), "Failed to send goal or goal was rejected.");
    return;
  }

  auto result_future = nav_client_->async_get_result(goal_handle_future.get());

  if (rclcpp::spin_until_future_complete(this->get_node_base_interface(), result_future, 60s) !=
      rclcpp::FutureReturnCode::SUCCESS) {
    RCLCPP_ERROR(this->get_logger(), "Navigation to goal did not complete successfully.");
    return;
  }

  // Access the actual result inside the WrappedResult
  auto result = result_future.get();

  if (result.result->success) {
    RCLCPP_INFO(this->get_logger(), "Navigation goal succeeded.");
  } else {
    RCLCPP_ERROR(this->get_logger(), "Navigation goal failed.");
  }

}

void MultiMapNavigator::switch_map(const std::string & map_name)
{
  // Create request
  auto request = std::make_shared<nav2_msgs::srv::LoadMap::Request>();
  request->map_url = "maps/" + map_name + ".yaml";  // Adjust this path to match your maps

  // Wait for service
  if (!map_load_client_->wait_for_service(5s)) {
    RCLCPP_ERROR(this->get_logger(), "Map load service not available");
    return;
  }

  // Call service
  auto future = map_load_client_->async_send_request(request);
  if (rclcpp::spin_until_future_complete(this->get_node_base_interface(), future, 5s) ==
      rclcpp::FutureReturnCode::SUCCESS)
  {
    RCLCPP_INFO(this->get_logger(), "Map switched to: %s", map_name.c_str());
    current_map_ = map_name;
    reset_amcl();
  }
  else
  {
    RCLCPP_ERROR(this->get_logger(), "Failed to switch map to: %s", map_name.c_str());
  }
}


void MultiMapNavigator::reset_amcl()
{
  RCLCPP_INFO(this->get_logger(), "Resetting AMCL via /initialpose...");
}

std::pair<double, double> MultiMapNavigator::get_wormhole_position(const std::string & map_name)
{
  double x = 0.0, y = 0.0;
  std::string sql = "SELECT x, y FROM wormholes WHERE map_name = ?";
  sqlite3_stmt * stmt;

  if (!db_) return {x, y};

  if (sqlite3_prepare_v2(db_, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
    sqlite3_bind_text(stmt, 1, map_name.c_str(), -1, SQLITE_TRANSIENT);

    if (sqlite3_step(stmt) == SQLITE_ROW) {
      x = sqlite3_column_double(stmt, 0);
      y = sqlite3_column_double(stmt, 1);
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
  pose.header.stamp = now();
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

