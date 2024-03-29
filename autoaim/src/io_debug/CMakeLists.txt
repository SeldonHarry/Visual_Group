cmake_minimum_required(VERSION 3.8)
project(io_debug)
set(CORE "coreio")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON) # 这一行很重要，没有的话可能会编译不成功

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(my_interfaces REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(Threads REQUIRED)

add_library(${PROJECT_NAME} SHARED src/io_debug.cpp)
add_library(${CORE} SHARED src/coreio.cpp)## change here
ament_target_dependencies(${PROJECT_NAME} rclcpp my_interfaces rclcpp_components)
ament_target_dependencies(${CORE} rclcpp my_interfaces rclcpp_components)

add_subdirectory(serial)
add_subdirectory(minipc_comm)
target_link_libraries(${PROJECT_NAME} serial minipc_comm)
target_include_directories(${PROJECT_NAME} PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/>"
    "$<INSTALL_INTERFACE:include/${PROJECT_NAME}>"
)

target_link_libraries(${CORE} serial minipc_comm)
target_include_directories(${CORE} PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/>"
    "$<INSTALL_INTERFACE:include/${PROJECT_NAME}>"
)

install(TARGETS
  ${PROJECT_NAME}
  DESTINATION lib
)

install(TARGETS
  ${CORE}
  DESTINATION lib
)

rclcpp_components_register_node(${PROJECT_NAME}
  PLUGIN minipc::MiniPcNode
  EXECUTABLE ${PROJECT_NAME}_node
)

rclcpp_components_register_node(${CORE}
  PLUGIN coreio::MiniPcNode
  EXECUTABLE ${CORE}_node
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
