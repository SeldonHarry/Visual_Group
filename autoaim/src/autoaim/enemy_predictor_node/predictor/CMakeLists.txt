cmake_minimum_required(VERSION 3.5)
set(lib_name predictor_lib)

find_package(OpenCV REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(ament_cmake REQUIRED)
find_package(ros2addon REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})
include_directories(${ros2addon_INCLUDE_DIRS})
include_directories(.)

aux_source_directory(./aim aim_src)
aux_source_directory(./enemy enemy_src)
aux_source_directory(./motion motion_src)
aux_source_directory(./pnp pnp_src)
aux_source_directory(./enemy_predictor enemy_predictor_src)
add_library(${lib_name} SHARED ${aim_src} ${enemy_src} ${pnp_src}
    ${enemy_predictor_src} ${motion_src})
target_link_libraries(${lib_name} ${OpenCV_LIBS})
ament_target_dependencies(${lib_name} ros2addon)

target_compile_options(${lib_name} PRIVATE -fPIC)

install(
    TARGETS ${lib_name}
    DESTINATION lib
)