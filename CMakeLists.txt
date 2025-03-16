cmake_minimum_required(VERSION 3.22)

project(testproj)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(header)
add_subdirectory(src)
