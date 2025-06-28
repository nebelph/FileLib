cmake_minimum_required(VERSION 3.10)
project(FileLib)

set(CMAKE_CXX_STANDARD 17)

add_executable(file_lib_prog
    ${CMAKE_SOURCE_DIR}/main.cpp
    ${CMAKE_SOURCE_DIR}/source/FileHandler.cpp
)

target_include_directories(file_lib_prog PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)