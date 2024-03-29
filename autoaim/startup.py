import os

from ament_index_python.packages import get_package_share_directory, get_package_prefix
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    params_file = 'config/sensor.yaml'

    camera_info_url = 'package://sensor/config/camera_info.yaml'
    camera_config_url = 'assets/MV-CA016-10UC_00K31937955.mfs'

    return LaunchDescription([
        DeclareLaunchArgument(name='params_file',
                              default_value=params_file),
        DeclareLaunchArgument(name='camera_info_url',
                              default_value=camera_info_url),
        DeclareLaunchArgument(name='use_sensor_data_qos',
                              default_value='false'),
        DeclareLaunchArgument(name='camera_config_url',
                              default_value=camera_config_url),
        DeclareLaunchArgument(name='predictor_config_url',
                              default_value='config/predictor.yaml'),

        Node(
            package='sensor',
            executable='sensor_node',
            output='screen',
            emulate_tty=True,
            parameters=[LaunchConfiguration('params_file'), {
                'camera_info_url': LaunchConfiguration('camera_info_url'),
                'use_sensor_data_qos': LaunchConfiguration('use_sensor_data_qos'),
                'camera_config_url': LaunchConfiguration('camera_config_url')
            }]
        ),Node(
            package='armor_detector',
            executable='armor_detector_node',
            output='screen',
            parameters=[]
        ),Node(
            package='enemy_predictor',
            executable='enemy_predictor_node',
            output='screen',
            parameters=[LaunchConfiguration('predictor_config_url')]
        ),Node(
            package='io_debug',
            executable='coreio_node',
            output='screen',
        )
    ])