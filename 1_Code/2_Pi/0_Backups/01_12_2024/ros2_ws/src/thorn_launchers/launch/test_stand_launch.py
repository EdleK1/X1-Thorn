from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='test_stand',
            name='Load_Cell_Reader_node',
            executable='Load_Cell_Reader_node',
        ),
        Node(
            package='test_stand',
            name='Test_Stand_Planner_node',
            executable='Test_Stand_Planner_node',
        ),
    ])