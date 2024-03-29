cmake_minimum_required(VERSION 3.5)
project(armor_detector)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wno-deprecated-declarations)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -march=native -flto")
## Export compile commands for clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# find dependencies
find_package(ament_cmake_auto REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)
ament_auto_find_build_dependencies()
find_package(image_transport REQUIRED)
find_package(rclcpp REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(camera_info_manager REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(my_interfaces REQUIRED)
find_package(ros2addon REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(fmt REQUIRED)
find_package(aimer_base REQUIRED)
find_package(CUDA REQUIRED)
include_directories(${PROJECT_NAME} detector_cuda)

ament_auto_add_library(${PROJECT_NAME} SHARED src/armor_detector_node.cpp)
ament_target_dependencies(${PROJECT_NAME} rclcpp)
ament_target_dependencies(${PROJECT_NAME} image_transport)
ament_target_dependencies(${PROJECT_NAME} camera_info_manager)
ament_target_dependencies(${PROJECT_NAME} my_interfaces)
ament_target_dependencies(${PROJECT_NAME} ros2addon)
ament_target_dependencies(${PROJECT_NAME} sensor_msgs)
ament_target_dependencies(${PROJECT_NAME} cv_bridge)
ament_target_dependencies(${PROJECT_NAME} aimer_base)
ament_target_dependencies(${PROJECT_NAME} CUDA)

target_include_directories(${PROJECT_NAME} PRIVATE ${ros2addon_INCLUDE_DIRS})

add_subdirectory(./detector_cuda)
target_link_libraries(${PROJECT_NAME} detector_cuda)
target_link_libraries(${LIB_NAME} fmt::fmt)

rclcpp_components_register_node(${PROJECT_NAME}
  PLUGIN detector::DetectorNode
  EXECUTABLE ${PROJECT_NAME}_node
)

ament_auto_package(
  INSTALL_TO_SHARE
  launch
)