cmake_minimum_required(VERSION 3.8)
project(file_io)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(OpenCV 4 REQUIRED)
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(my_interfaces REQUIRED)
find_package(image_transport REQUIRED)
find_package(camera_info_manager REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(cv_bridge REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
add_subdirectory(minipc_comm) # subdirectory 要一个一个加

add_library(${PROJECT_NAME} SHARED src/file_io.cpp)
ament_target_dependencies(${PROJECT_NAME} rclcpp rclcpp_components my_interfaces image_transport camera_info_manager sensor_msgs geometry_msgs cv_bridge)

target_include_directories(${PROJECT_NAME} PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/>"
    "$<INSTALL_INTERFACE:include/${PROJECT_NAME}>"
)
target_link_libraries(${PROJECT_NAME} minipc_comm)

# fakeio library
set(FAKE "fakeio")
add_library(${FAKE} SHARED src/fake_fileio.cpp)
ament_target_dependencies(${FAKE} rclcpp rclcpp_components my_interfaces image_transport camera_info_manager sensor_msgs geometry_msgs cv_bridge)
target_include_directories(${FAKE} PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/>"
    "$<INSTALL_INTERFACE:include/${PROJECT_NAME}>"
)
target_link_libraries(${FAKE} minipc_comm ${OpenCV_LIBS})

install(TARGETS
  ${PROJECT_NAME}
  DESTINATION lib
)

install(TARGETS
  ${FAKE}
  DESTINATION lib
)
rclcpp_components_register_node(${FAKE}
  PLUGIN fakeio::FakeioNode
  EXECUTABLE ${FAKE}_node
)
# install(
#   DIRECTORY launch
#   DESTINATION share/${FAKE}
# )

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
