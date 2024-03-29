from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        DeclareLaunchArgument(name='fakeio_file',default_value='config/fakeio.yaml'),
    Node(
        package="file_io",
        executable="fakeio_node",
        output="screen",
        name="fakeio_node",
        emulate_tty=True,
        parameters=[
            LaunchConfiguration("fakeio_file")
        ]
    )
    ])