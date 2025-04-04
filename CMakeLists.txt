cmake_minimum_required(VERSION 3.22 FATAL_ERROR)

project(testproj LANGUAGES CXX)

enable_language(CUDA)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/executable)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


set(CMAKE_CUDA_ARCHITECTURES 80)

include(cmake/CPM.cmake)
include(cmake/cccl.cmake)

find_package(CUDAToolkit)
find_package(OpenMP)

include_directories(header)

add_subdirectory(src)
