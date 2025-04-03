set_source_files_properties(main.cpp PROPERTIES LANGUAGE CUDA)

# Define an executable target from main.cpp
add_executable(testexe main.cpp)

# Link Eigen library to the testexe executable
target_link_libraries(testexe PRIVATE CCCL::CUB CCCL::Thrust )
target_link_libraries(testexe PRIVATE ${CUDA_LIBRARIES})

if(OPENMP_FOUND)
    target_link_libraries(testexe PRIVATE OpenMP::OpenMP_CXX) 
    target_compile_options(testexe PRIVATE $<$<COMPILE_LANGUAGE:CUDA>:${OpenMP_CXX_FLAGS}>)
endif()
