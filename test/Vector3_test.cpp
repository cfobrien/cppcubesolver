#include "Vector3.cpp"
#include <iostream>
#include "gtest/gtest.h"

namespace{
    TEST(OperatorTest, Eq) {
        EXPECT_EQ(Vector3(1,2,3), Vector3(1,2,3));
        EXPECT_NE(Vector3(1,2,3), Vector3(-1,-2,-3));
        EXPECT_TRUE(Vector3(1,2,3) == Vector3(1,2,3));
        EXPECT_FALSE(Vector3(1,2,3) == Vector3(-1,-2,-3));
        EXPECT_TRUE(Vector3(1,2,3) != Vector3(-1,-2,-3));
        EXPECT_FALSE(Vector3(1,2,3) != Vector3(1,2,3));

    }
    TEST(OperatorTest, Add) {
        EXPECT_EQ(Vector3(1,2,3), Vector3(-3,-2,-1)+Vector3(4,4,4));
        EXPECT_NE(Vector3(0,0,0), Vector3(1,2,3) + Vector3(0,0,0));
    }

}