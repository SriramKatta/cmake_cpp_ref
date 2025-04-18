# Define an executable target from main.cpp
add_executable(testexe main.cpp)

# Link Eigen library to the testexe executable
target_link_libraries(testexe PRIVATE Boost::headers)
target_link_libraries(testexe PRIVATE Boost::program_options)