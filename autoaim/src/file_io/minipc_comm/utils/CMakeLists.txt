project(utils)
cmake_minimum_required(VERSION 3.8)

aux_source_directory(. SOURCES)

add_library(${PROJECT_NAME} ${SOURCES})
