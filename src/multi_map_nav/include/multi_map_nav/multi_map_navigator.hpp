#ifndef MULTI_MAP_NAV__MULTI_MAP_NAVIGATOR_HPP_
#define MULTI_MAP_NAV__MULTI_MAP_NAVIGATOR_HPP_

#include <rclcpp/rclcpp.hpp>
#include <rclcpp_action/rclcpp_action.hpp>
#include <geometry_msgs/msg/pose_with_covariance_stamped.hpp>
#include <multi_map_nav_interfaces/action/multi_map_navigate.hpp>
#include <sqlite3.h>
#include <string>
#include <utility>
#include <memory>
#include <thread>

#include "nav2_msgs/srv/load_map.hpp"

class MultiMapNavigator : public rclcpp::Node
{
public:
  MultiMapNavigator();
  ~MultiMapNavigator();

  void send_goal(double x, double y, double theta, const std::string & target_map);
  void switch_map(const std::string & map_name);
  void reset_amcl();
  std::pair<double, double> get_wormhole_position(const std::string & map_name);

private:
  using MultiMapNavigate = multi_map_nav_interfaces::action::MultiMapNavigate;
  using GoalHandle = rclcpp_action::ServerGoalHandle<MultiMapNavigate>;

  // Action Client
  rclcpp_action::Client<MultiMapNavigate>::SharedPtr nav_client_;

  // Action Server
  rclcpp_action::Server<MultiMapNavigate>::SharedPtr action_server_;

  // AMCL reset publisher
  rclcpp::Publisher<geometry_msgs::msg::PoseWithCovarianceStamped>::SharedPtr initialpose_pub_;
  
  //Map load client for switching maps
  rclcpp::Client<nav2_msgs::srv::LoadMap>::SharedPtr map_load_client_;  

  // SQLite DB
  sqlite3 * db_;

  // Current map
  std::string current_map_;

  // Action server callbacks
  rclcpp_action::GoalResponse handle_goal(const rclcpp_action::GoalUUID & uuid,
                                          std::shared_ptr<const MultiMapNavigate::Goal> goal);

  rclcpp_action::CancelResponse handle_cancel(const std::shared_ptr<GoalHandle> goal_handle);

  void handle_accepted(const std::shared_ptr<GoalHandle> goal_handle);

  void execute_navigation(const std::shared_ptr<GoalHandle> goal_handle);
};

#endif  // MULTI_MAP_NAV__MULTI_MAP_NAVIGATOR_HPP_

