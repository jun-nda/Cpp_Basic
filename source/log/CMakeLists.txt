cmake_minimum_required(VERSION 3.16)
project(Log)

add_executable(Log log.cpp)
target_include_directories(Log PUBLIC 
    "${PROJECT_SOURCE_DIR}/../../external/include" 
)