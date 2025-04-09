#include "gtest/gtest.h"

#include "test_header.hpp"



TEST(basictest, test1)
{
    ASSERT_EQ(test::return42(), 42) << "ERROR IN THE FUNCTION";
}

TEST(basictest, test2)
{
    ASSERT_EQ(test::return42(10.0), 42) << "ERROR IN THE FUNCTION";
}
TEST(basictest, test3)
{
    ASSERT_EQ(test::return42('c'), 42) << "ERROR IN THE FUNCTION";
}

TEST(sanju, test1){
    ASSERT_NE(test::return42(), 41) << "Error in function";
}