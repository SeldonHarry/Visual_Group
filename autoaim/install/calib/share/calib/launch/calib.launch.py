from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='calib',
            executable='calib_node',
            output='screen',
            emulate_tty=True,
            parameters=[],
            #namespace='calibrate',
        )
    ])
