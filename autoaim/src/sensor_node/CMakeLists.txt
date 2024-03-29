cmake_minimum_required(VERSION 3.5)
project(sensor)

# Use C++14
set(CMAKE_CXX_STANDARD 14)

## Export compile commands for clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# find dependencies
find_package(ament_cmake_auto REQUIRED)
ament_auto_find_build_dependencies()
find_package(image_transport REQUIRED)
find_package(camera_info_manager REQUIRED)
find_package(rclcpp_components REQUIRED)

ament_auto_add_library(${PROJECT_NAME} SHARED
  src/sensor_node.cpp
)
ament_target_dependencies(${PROJECT_NAME} image_transport)
ament_target_dependencies(${PROJECT_NAME} camera_info_manager)

target_include_directories(${PROJECT_NAME} PUBLIC hikSDK/include)
target_include_directories(${PROJECT_NAME} PUBLIC ExtImu)
target_include_directories(${PROJECT_NAME} PUBLIC serial/include)

add_subdirectory(ExtImu)
add_subdirectory(serial)
target_link_libraries(${PROJECT_NAME} serial_lib ExtImu)


# found hikvision camera SDK directory automatically according to device architecture
if(CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64")
  target_link_directories(${PROJECT_NAME} PUBLIC hikSDK/lib/amd64)
  install(
    DIRECTORY hikSDK/lib/amd64/
    DESTINATION lib
  )
elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "aarch64")
  target_link_directories(${PROJECT_NAME} PUBLIC hikSDK/lib/arm64)
  install(
    DIRECTORY hikSDK/lib/arm64/
    DESTINATION lib
  )
else()
  message(FATAL_ERROR "Unsupport host system architecture: ${CMAKE_HOST_SYSTEM_PROCESSOR}!")
endif()

target_link_libraries(${PROJECT_NAME}
  FormatConversion
  MediaProcess
  MvCameraControl
  MVRender
  MvUsb3vTL
)

rclcpp_components_register_node(${PROJECT_NAME}
  PLUGIN sensor::SensorNode
  EXECUTABLE ${PROJECT_NAME}_node
)

ament_auto_package(
  INSTALL_TO_SHARE
  config
  launch
)