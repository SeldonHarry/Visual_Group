cmake_minimum_required(VERSION 3.5)
project(enemy_predictor)

# set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -march=native")
## Export compile commands for clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


# find dependencies
find_package(ament_cmake_auto REQUIRED)
ament_auto_find_build_dependencies()
find_package(rclcpp_components REQUIRED)
find_package(my_interfaces REQUIRED)
find_package(ros2addon REQUIRED)
find_package(aimer_base REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)
include_directories(${aimer_base_INCLUDE_DIR})
include_directories(./predictor)
add_subdirectory(./predictor)
ament_auto_add_library(${PROJECT_NAME} SHARED src/predictor_node.cpp)

target_link_libraries(${PROJECT_NAME} predictor_lib)
ament_target_dependencies(${PROJECT_NAME} my_interfaces)
ament_target_dependencies(${PROJECT_NAME} ros2addon)
ament_target_dependencies(${PROJECT_NAME} aimer_base)

rclcpp_components_register_node(${PROJECT_NAME}
  PLUGIN predictor::PredictorNode
  EXECUTABLE ${PROJECT_NAME}_node
)

ament_auto_package()
