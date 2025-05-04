#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "multi_map_nav_interfaces/action/multi_map_navigate.hpp"
#include <thread>

using MultiMapNavigate = multi_map_nav_interfaces::action::MultiMapNavigate;
using GoalHandleMultiMapNavigate = rclcpp_action::ServerGoalHandle<MultiMapNavigate>;

class MultiMapNavigatorServer : public rclcpp::Node
{
public:
  MultiMapNavigatorServer()
  : Node("multi_map_navigator_server")
  {
    action_server_ = rclcpp_action::create_server<MultiMapNavigate>(
      this,
      "multi_map_navigator",
      std::bind(&MultiMapNavigatorServer::handle_goal, this, std::placeholders::_1, std::placeholders::_2),
      std::bind(&MultiMapNavigatorServer::handle_cancel, this, std::placeholders::_1),
      std::bind(&MultiMapNavigatorServer::handle_accepted, this, std::placeholders::_1)
    );
  }

private:
  rclcpp_action::Server<MultiMapNavigate>::SharedPtr action_server_;

  rclcpp_action::GoalResponse handle_goal(
    const rclcpp_action::GoalUUID &,
    std::shared_ptr<const MultiMapNavigate::Goal> goal)
  {
    RCLCPP_INFO(this->get_logger(), "Goal received for map: %s", goal->target_map.c_str());
    return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
  }

  rclcpp_action::CancelResponse handle_cancel(
    const std::shared_ptr<GoalHandleMultiMapNavigate> goal_handle)
  {
    RCLCPP_INFO(this->get_logger(), "Cancel request received");
    return rclcpp_action::CancelResponse::ACCEPT;
  }

  void handle_accepted(const std::shared_ptr<GoalHandleMultiMapNavigate> goal_handle)
  {
    std::thread(&MultiMapNavigatorServer::execute, this, goal_handle).detach();
  }

  void execute(const std::shared_ptr<GoalHandleMultiMapNavigate> goal_handle)
  {
    auto goal = goal_handle->get_goal();
    auto feedback = std::make_shared<MultiMapNavigate::Feedback>();
    auto result = std::make_shared<MultiMapNavigate::Result>();

    RCLCPP_INFO(this->get_logger(), "Executing navigation to (%.2f, %.2f) on map %s",
                goal->x, goal->y, goal->target_map.c_str());

    feedback->current_status = "Navigating...";
    goal_handle->publish_feedback(feedback);

    std::this_thread::sleep_for(std::chrono::seconds(3));  // Simulate action delay

    result->success = true;
    RCLCPP_INFO(this->get_logger(), "Navigation complete.");
    goal_handle->succeed(result);
  }
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MultiMapNavigatorServer>());
  rclcpp::shutdown();
  return 0;
}

