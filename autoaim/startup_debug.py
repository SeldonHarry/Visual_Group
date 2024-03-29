import os

from ament_index_python.packages import get_package_share_directory, get_package_prefix
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    camera_info_url = 'package://sensor/config/camera_info.yaml'
    camera_config_url = os.path.join(
        get_package_share_directory('sensor'), 'config', 'MV-CA016-10UC_00K31937955.mfs')

    return LaunchDescription([
        DeclareLaunchArgument(name='camera_info_url',
                              default_value=camera_info_url),
        DeclareLaunchArgument(name='use_sensor_data_qos',
                              default_value='false'),
        DeclareLaunchArgument(name='camera_config_url',
                              default_value=camera_config_url),
        DeclareLaunchArgument(name='predictor_config_url',
                              default_value='config/predictor.yaml'),
        DeclareLaunchArgument(name='fakeio_file',
                              default_value='config/fakeio.yaml'),

        Node(
            package="file_io",
            executable="fakeio_node",
            output="screen",
            name="fakeio_node",
            emulate_tty=True,
            parameters=[
                LaunchConfiguration("fakeio_file")
            ]
        ),Node(
            package='armor_detector',
            executable='armor_detector_node',
            output='screen',
            parameters=[]
        ),
        Node(
            package='enemy_predictor',
            executable='enemy_predictor_node',
            output='screen',
            parameters=[LaunchConfiguration('predictor_config_url')]
        ),
        Node(
            package='web_debugger',
            executable='web_debugger',
            output='screen',
            parameters=[]
        )
    ])