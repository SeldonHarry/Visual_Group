from launch import LaunchDescription
from launch_ros.actions import Node
STORE_PATH="/home/amov/Documents/assets/"

def generate_launch_description():
    return LaunchDescription([
        Node(
            package="record",
            executable="record_node",
            name="record_node",
            output="screen",
            emulate_tty=True,#these two lines before ensure the output is printed on the console
            parameters=[
                {"storage_location",STORE_PATH},
            ]
        )
    ])