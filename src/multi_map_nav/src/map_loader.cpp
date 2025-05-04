// map_loader_node.cpp

#include "rclcpp/rclcpp.hpp"
#include "std_srvs/srv/empty.hpp"

class MapLoaderNode : public rclcpp::Node {
public:
  MapLoaderNode() : Node("map_loader") {
    service_ = this->create_service<std_srvs::srv::Empty>(
      "map_loader/reload",
      std::bind(&MapLoaderNode::handle_reload, this, std::placeholders::_1, std::placeholders::_2)
    );
    RCLCPP_INFO(this->get_logger(), "Map reload service ready.");
  }

private:
  void handle_reload(const std::shared_ptr<std_srvs::srv::Empty::Request> request,
                     std::shared_ptr<std_srvs::srv::Empty::Response> response)
  {
    (void)request;
    (void)response;

    // Load the map file from parameter
    std::string map_file;
    if (!this->get_parameter("map_file", map_file)) {
      RCLCPP_ERROR(this->get_logger(), "No map_file parameter set.");
      return;
    }

    // Normally you'd call nav2_map_server here or publish to a topic
    RCLCPP_INFO(this->get_logger(), "Reloading map from: %s", map_file.c_str());

    // Trigger reload logic here...
  }

  rclcpp::Service<std_srvs::srv::Empty>::SharedPtr service_;
};

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MapLoaderNode>());
  rclcpp::shutdown();
  return 0;
}

