from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    os.environ['TURTLEBOT3_MODEL'] = 'burger'

    map_file = os.path.join(get_package_share_directory('multi_map_nav'), 'maps', 'room1.yaml')
    param_file = os.path.join(get_package_share_directory('turtlebot3_navigation2'), 'param', 'burger.yaml')

    if not os.path.exists(map_file):
        raise FileNotFoundError(f"Map file not found: {map_file}")

    return LaunchDescription([
        # Launch Gazebo
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                os.path.join(
                    get_package_share_directory('turtlebot3_gazebo'),
                    'launch',
                    'turtlebot3_world.launch.py'
                )
            ),
            launch_arguments={'use_sim_time': 'true'}.items(),
        ),

        # Launch Nav2
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                os.path.join(
                    get_package_share_directory('turtlebot3_navigation2'),
                    'launch',
                    'navigation2.launch.py'
                )
            ),
            launch_arguments={
                'map': map_file,
                'use_sim_time': 'true',
                'params_file': param_file,
                'use_amcl': 'false' 
            }.items(),
        ),

        # Launch your multi-map navigation node
        Node(
            package='multi_map_nav',
            executable='multi_map_navigator_node',
            name='multi_map_navigator_node',
            output='screen',
            parameters=[{'use_sim_time': True}]
        ),

        # Launch AMCL Node
        Node(
            package='nav2_amcl',
            executable='amcl',
            name='amcl',
            output='screen',
            parameters=[{'use_sim_time': True}]
        ),

        # Launch the map loader (map reloading service)
        Node(
            package='multi_map_nav',
            executable='map_loader_node',
            name='map_loader_node',
            output='screen'
        ),

        # Launch the AMCL reset node (reset AMCL pose service)
        Node(
            package='multi_map_nav',
            executable='amcl_reset_node',
            name='amcl_reset_node',
            output='screen'
        ),
    ])

