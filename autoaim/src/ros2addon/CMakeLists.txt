cmake_minimum_required(VERSION 3.8)
project(ros2addon)

set(CMAKE_CXX_STANDARD 17)
# export compile commands for clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -march=native")

find_package(ament_cmake_auto REQUIRED)

include_directories(${PROJECT_NAME} "../../base")
ament_auto_find_build_dependencies()
find_package(rclcpp REQUIRED)
find_package(OpenCV REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(Ceres REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(aimer_base REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})
aux_source_directory(./src src)

ament_auto_add_library(${PROJECT_NAME} SHARED ${src})
ament_target_dependencies(${PROJECT_NAME} rclcpp)
ament_target_dependencies(${PROJECT_NAME} cv_bridge)
ament_target_dependencies(${PROJECT_NAME} sensor_msgs)
ament_target_dependencies(${PROJECT_NAME} aimer_base)

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
target_link_libraries(${PROJECT_NAME} ${CERES_LIBRARIES})
target_include_directories(${PROJECT_NAME} PUBLIC ./include)

ament_auto_package()