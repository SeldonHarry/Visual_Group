cmake_minimum_required(VERSION 3.8)
project(fast_record)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
# find dependencies
find_package(OpenCV 4 REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(my_interfaces REQUIRED)
find_package(image_transport REQUIRED)
find_package(camera_info_manager REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(cv_bridge REQUIRED)
# if auto
# find_package(ament_cmake_auto REQUIRED)
# ament_auto_find_build_dependencies()

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${EIGEN3_INCLUDE_DIRS})

add_library(${PROJECT_NAME} SHARED src/record.cpp)
ament_target_dependencies(${PROJECT_NAME} rclcpp rclcpp_components my_interfaces image_transport camera_info_manager sensor_msgs geometry_msgs cv_bridge)

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})# 先不写eigen

install(TARGETS
  ${PROJECT_NAME}
  DESTINATION lib
)

rclcpp_components_register_node(${PROJECT_NAME}
  PLUGIN recorder::RecorderNode
  EXECUTABLE ${PROJECT_NAME}_node
)

install(
  DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
