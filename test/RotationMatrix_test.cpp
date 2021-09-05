#include "Vector3.h"
#include "RotationMatrix.h"
#include <iostream>
#include "gtest/gtest.h"

namespace{
    TEST(TransformTest, Rotate) {
        EXPECT_EQ(Vector3::ones(), RotationMatrix::identity() * Vector3::ones());
        EXPECT_EQ(Vector3::X(), RotationMatrix(Vector3::X(), 42.0) * Vector3::X());
        EXPECT_EQ(RotationMatrix(Vector3::X(), 90.0) * Vector3::Y(), Vector3(0,0,-1));
    }

    TEST(TransformTest, Operator) {
        EXPECT_EQ(RotationMatrix::identity() * Vector3::ones(),
                  Vector3::ones() * RotationMatrix::identity());
    }
}
