project(minipc_comm)
cmake_minimum_required(VERSION 3.8)

add_subdirectory(serial_comm)
aux_source_directory(. SOURCES)

add_library(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} serial_comm)
ament_target_dependencies(${PROJECT_NAME} rclcpp) # can only be put at last