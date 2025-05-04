// amcl_reset_node.cpp

#include "rclcpp/rclcpp.hpp"
#include "std_srvs/srv/empty.hpp"
#include "geometry_msgs/msg/pose_with_covariance_stamped.hpp"

class AMCLResetNode : public rclcpp::Node {
public:
  AMCLResetNode() : Node("amcl_reset_node") {
    service_ = this->create_service<std_srvs::srv::Empty>(
      "amcl/reset_pose",
      std::bind(&AMCLResetNode::handle_reset, this, std::placeholders::_1, std::placeholders::_2)
    );

    pub_ = this->create_publisher<geometry_msgs::msg::PoseWithCovarianceStamped>("initialpose", 10);
    RCLCPP_INFO(this->get_logger(), "AMCL reset_pose service ready.");
  }

private:
  void handle_reset(const std::shared_ptr<std_srvs::srv::Empty::Request> request,
                    std::shared_ptr<std_srvs::srv::Empty::Response> response)
  {
    (void)request;
    (void)response;

    geometry_msgs::msg::PoseWithCovarianceStamped init_pose;
    init_pose.header.stamp = this->get_clock()->now();
    init_pose.header.frame_id = "map";
    init_pose.pose.pose.position.x = 0.0;
    init_pose.pose.pose.position.y = 0.0;
    init_pose.pose.pose.orientation.w = 1.0;

    // Add small covariance
    init_pose.pose.covariance[0] = 0.25;
    init_pose.pose.covariance[7] = 0.25;
    init_pose.pose.covariance[35] = 0.06853891945200942;

    pub_->publish(init_pose);
    RCLCPP_INFO(this->get_logger(), "Published initial pose to reset AMCL.");
  }

  rclcpp::Publisher<geometry_msgs::msg::PoseWithCovarianceStamped>::SharedPtr pub_;
  rclcpp::Service<std_srvs::srv::Empty>::SharedPtr service_;
};

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<AMCLResetNode>());
  rclcpp::shutdown();
  return 0;
}
