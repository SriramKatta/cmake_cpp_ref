if (BUILD_TESTING)
    add_executable(basictest maintest.cpp)
    target_link_libraries(basictest PRIVATE GTest::gtest_main)
    include(GoogleTest)
    # Finds all the Google tests associated with the executable
    gtest_discover_tests(basictest)
endif()