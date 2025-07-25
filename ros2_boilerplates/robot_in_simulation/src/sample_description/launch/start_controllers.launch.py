import os
import launch
from launch.substitutions import PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare
from launch_ros.actions import Node
from launch.launch_description_sources import PythonLaunchDescriptionSource

def generate_launch_description():

    robot_controllers = PathJoinSubstitution(
        [
            FindPackageShare('sample_description'),
            'config',
            'sample_robot_controllers.yaml',
        ]
    )


    joint_state_broadcaster_spawner = Node(
        package='controller_manager',
        executable='spawner',
        parameters=[{'use_sim_time': False}],
        arguments=['joint_state_broadcaster'],
    )

    joint_trajectory_controller_spawner = Node(
        package='controller_manager',
        executable='spawner',
        arguments=[
            'diff_controller',
            '--param-file',
            robot_controllers,
            ],
    )


    return launch.LaunchDescription([
        joint_state_broadcaster_spawner,
        joint_trajectory_controller_spawner
    ])
