project(serial_comm)
cmake_minimum_required(VERSION 3.8)

aux_source_directory(src SOURCES)
add_library(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC include)