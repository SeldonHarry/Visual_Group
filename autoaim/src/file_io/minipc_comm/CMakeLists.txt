project(minipc_comm)
cmake_minimum_required(VERSION 3.8)

add_subdirectory(utils)
aux_source_directory(. SOURCES)

add_library(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} utils)