cmake_minimum_required(VERSION 3.8)
project(my_interfaces)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# export compile commands for clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# find dependencies
find_package(ament_cmake_auto REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
ament_auto_find_build_dependencies()

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/AimShootMsgBoard2PC.msg"
  "msg/AimShootMsgPC2Board.msg"
  "msg/GameStatusPC2Board.msg"
  "msg/GameStatusMsgBoard2PC.msg"
  "msg/GeneralMsgBoard2PC.msg"
  "msg/GeneralMsgPC2Board.msg"
  "msg/DPackIdentifier.msg"
  "msg/NavigationBoard2PC.msg"
  "msg/NavigationPC2Board.msg"
  "msg/PCWorkMode.msg"
  "msg/RobotCmd.msg"
  "msg/RobotStatus.msg"
  "msg/DetectedArmor.msg"
  "msg/DetectionResult.msg"
  "msg/ReloadFlag.msg"
  "srv/DebugInfo.srv"
  DEPENDENCIES builtin_interfaces std_msgs geometry_msgs sensor_msgs
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_auto_package()
