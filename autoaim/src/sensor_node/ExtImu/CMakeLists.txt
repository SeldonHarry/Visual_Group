cmake_minimum_required(VERSION 3.5)
set(lib_name ExtImu)

add_library(${lib_name} SHARED ExtImu.cpp)
target_include_directories(${lib_name} PUBLIC ../serial/include)
install(TARGETS ${lib_name}
    DESTINATION lib)