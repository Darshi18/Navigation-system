#include <chrono>  // Required for duration literals like 2s, 5s
#include <rclcpp/rclcpp.hpp>
#include <rclcpp_action/rclcpp_action.hpp>
#include <multi_map_nav_interfaces/action/multi_map_navigate.hpp>

using namespace std::chrono_literals;

using MultiMapNavigate = multi_map_nav_interfaces::action::MultiMapNavigate;
using GoalHandleMultiMap = rclcpp_action::ClientGoalHandle<MultiMapNavigate>;

class MultiMapTestClient : public rclcpp::Node
{
public:
  MultiMapTestClient()
  : Node("multi_map_test_client")
  {
    client_ = rclcpp_action::create_client<MultiMapNavigate>(this, "multi_map_navigate");

    timer_ = this->create_wall_timer(
      2s, std::bind(&MultiMapTestClient::send_goal, this));
  }

private:
  rclcpp_action::Client<MultiMapNavigate>::SharedPtr client_;
  rclcpp::TimerBase::SharedPtr timer_;

  void send_goal()
  {
    timer_->cancel();  // Run only once

    if (!client_->wait_for_action_server(5s)) {
      RCLCPP_ERROR(this->get_logger(), "Action server not available.");
      return;
    }

    auto goal_msg = MultiMapNavigate::Goal();
    goal_msg.x = 2.0;
    goal_msg.y = 2.0;
    goal_msg.theta = 0.0;
    goal_msg.target_map = "room2";

    RCLCPP_INFO(this->get_logger(), "Sending goal to target map: %s", goal_msg.target_map.c_str());

    auto send_goal_options = rclcpp_action::Client<MultiMapNavigate>::SendGoalOptions();
    send_goal_options.result_callback = std::bind(&MultiMapTestClient::result_callback, this, std::placeholders::_1);
    send_goal_options.feedback_callback = std::bind(&MultiMapTestClient::feedback_callback, this, std::placeholders::_1, std::placeholders::_2);

    client_->async_send_goal(goal_msg, send_goal_options);
  }

  void feedback_callback(
    GoalHandleMultiMap::SharedPtr,
    const std::shared_ptr<const MultiMapNavigate::Feedback> feedback)
  {
    RCLCPP_INFO(this->get_logger(), "Feedback: %s", feedback->current_status.c_str());
  }

  void result_callback(const GoalHandleMultiMap::WrappedResult & result)
  {
    switch (result.code) {
      case rclcpp_action::ResultCode::SUCCEEDED:
        RCLCPP_INFO(this->get_logger(), "Navigation succeeded!");
        break;
      case rclcpp_action::ResultCode::ABORTED:
        RCLCPP_ERROR(this->get_logger(), "Navigation aborted");
        break;
      case rclcpp_action::ResultCode::CANCELED:
        RCLCPP_WARN(this->get_logger(), "Navigation canceled");
        break;
      default:
        RCLCPP_ERROR(this->get_logger(), "Unknown result code");
        break;
    }

    rclcpp::shutdown();
  }
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<MultiMapTestClient>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}

