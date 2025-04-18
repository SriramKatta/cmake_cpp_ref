# Define an executable target from main.cpp
add_executable(testexe main.cpp)

# Link Eigen library to the testexe executable
target_link_libraries(testexe PRIVATE Boost::headers)
target_link_libraries(testexe PRIVATE Boost::filesystem)
target_link_libraries(testexe PRIVATE Boost::mpi)
target_link_libraries(testexe PRIVATE Boost::serialization)
target_link_libraries(testexe PRIVATE fmt)