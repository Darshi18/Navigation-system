cmake_minimum_required(VERSION 3.8)
project(multi_map_nav)

# Compiler settings
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(nav2_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(sqlite3_vendor REQUIRED)
find_package(multi_map_nav_interfaces REQUIRED)
find_package(std_srvs REQUIRED)
find_package(nav2_amcl REQUIRED)

# =======================
# multi_map_navigator_node
# =======================
add_executable(multi_map_navigator_node
  src/main.cpp
  src/multi_map_navigator.cpp
)

target_include_directories(multi_map_navigator_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

target_link_libraries(multi_map_navigator_node sqlite3)

ament_target_dependencies(multi_map_navigator_node
  rclcpp
  rclcpp_action
  geometry_msgs
  nav2_msgs
  sqlite3_vendor
  multi_map_nav_interfaces
  std_srvs
  nav2_amcl
)

install(TARGETS multi_map_navigator_node
  DESTINATION lib/${PROJECT_NAME}
)

# =======================
# multi_map_navigator_server (Action Server)
# =======================
add_executable(multi_map_navigator_server
  src/multi_map_navigator_server.cpp
)

target_include_directories(multi_map_navigator_server PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

ament_target_dependencies(multi_map_navigator_server
  rclcpp
  rclcpp_action
  multi_map_nav_interfaces
)

install(TARGETS multi_map_navigator_server
  DESTINATION lib/${PROJECT_NAME}
)

# =======================
# map_loader_node
# =======================
add_executable(map_loader_node
  src/map_loader.cpp
)

target_include_directories(map_loader_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

ament_target_dependencies(map_loader_node
  rclcpp
  std_srvs
)

install(TARGETS map_loader_node
  DESTINATION lib/${PROJECT_NAME}
)

# =======================
# amcl_reset_node
# =======================
add_executable(amcl_reset_node
  src/amcl_reset_node.cpp
)

target_include_directories(amcl_reset_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

ament_target_dependencies(amcl_reset_node
  rclcpp
  std_srvs
  nav2_amcl
)

install(TARGETS amcl_reset_node
  DESTINATION lib/${PROJECT_NAME}
)

# =======================
# multi_map_test_client
# =======================
add_executable(multi_map_test_client
  src/multi_map_test_client.cpp
)

target_include_directories(multi_map_test_client PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

ament_target_dependencies(multi_map_test_client
  rclcpp
  rclcpp_action
  geometry_msgs
  multi_map_nav_interfaces
)

install(TARGETS multi_map_test_client
  DESTINATION lib/${PROJECT_NAME}
)

# =======================
# Other installs (launch/maps)
# =======================
install(DIRECTORY launch/
  DESTINATION share/${PROJECT_NAME}/launch
)

install(DIRECTORY maps
  DESTINATION share/${PROJECT_NAME}
)

# Final package macro
ament_package()
