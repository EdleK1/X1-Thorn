from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='joy',
            name='joy_node',
            executable='joy_node',
        ),
        Node(
            package='thorn_planners',
            name='Flight_Planner_node',
            executable='Flight_Planner_node',
        ),
    ])