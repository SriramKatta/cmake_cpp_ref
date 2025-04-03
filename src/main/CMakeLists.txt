# Define an executable target from main.cpp
add_executable(testexe main.cpp)

# Link Eigen library to the testexe executable
target_link_libraries(testexe PRIVATE Eigen)