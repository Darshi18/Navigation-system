#include "rclcpp/rclcpp.hpp"
#include "multi_map_nav/multi_map_navigator.hpp"

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<MultiMapNavigator>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
