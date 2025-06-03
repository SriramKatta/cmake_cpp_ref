CPMAddPackage(
  NAME matplotlib-cpp
  GITHUB_REPOSITORY lava/matplotlib-cpp
  GIT_TAG master
  OPTIONS
    MATPLOTLIB_CPP_SKIP_EXAMPLES ON
    DOWNLOAD_ONLY YES
)

add_library(matplotlib_cpp INTERFACE)
target_include_directories(matplotlib_cpp INTERFACE ${matplotlib-cpp_SOURCE_DIR})
find_package(Python3 REQUIRED COMPONENTS Interpreter Development NumPy)
target_include_directories(matplotlib_cpp INTERFACE ${Python3_INCLUDE_DIRS} ${Python3_NumPy_INCLUDE_DIRS})
target_link_libraries(matplotlib_cpp INTERFACE ${Python3_LIBRARIES})
