cmake_minimum_required(VERSION 3.15)
project(aimer_base)

set(CMAKE_CXX_STANDARD 17)
# export compile commands for clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -march=native -flto")

set(OpenCV_VERSION 4.7.0)
find_package(ament_cmake_auto REQUIRED)
find_package(OpenCV 4 REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(Ceres REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${EIGEN3_INCLUDE_DIR})
include_directories(${CERES_INCLUDE_DIRS})
include_directories(./include)

# 搜集目录中所有源文件，存储到变量中
aux_source_directory(./src src)

# 编译变量的源文件并生成对象库
ament_auto_add_library(${PROJECT_NAME} SHARED ${src})

# 链接库
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS} ${CERES_LIBRARIES})

ament_auto_package()