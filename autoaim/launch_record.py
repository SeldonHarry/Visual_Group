from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
            DeclareLaunchArgument(name='record_file',
                              default_value='config/record.yaml'),
        Node(
            package="fast_record",
            executable="fast_record_node",
            output="screen",
            name="fast_record", # this shoule be in accrod with that in .yaml file
            emulate_tty=True,#these two lines before ensure the output is printed on the console
            parameters=[
                LaunchConfiguration('record_file')
            ]
        )
    ])