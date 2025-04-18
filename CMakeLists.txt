# Set the minimum required CMake version and enforce it strictly
cmake_minimum_required(VERSION 3.28 FATAL_ERROR)

# Define the project name
project(testproj)

# Store compiled executables in a separate folder
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/executable)

# Export compile_commands.json for reviewing compilation details
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Load CPM (CMake Package Manager) for dependency management
include(cmake/CPM.cmake)

# Load Eigen library settings
include(cmake/boost.cmake)

# Include the "header" directory for header files
include_directories(header)

# Add the "src" directory as a subdirectory for compilation
add_subdirectory(src)
