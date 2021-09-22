#include "RotationMatrix.h"
#include "gtest/gtest.h"

namespace {
    TEST(RotationMatrixTransformTest, Rotate) {
        EXPECT_EQ(Vector3::ones(), RotationMatrix::identity() * Vector3::ones());
        EXPECT_EQ(Vector3::X(), RotationMatrix(Vector3::X(), M_PI/42.0) * Vector3::X());
        EXPECT_EQ(RotationMatrix(Vector3::X(), -M_PI/2) * Vector3::Y(), Vector3::Z());
    }

    TEST(RotationMatrixTransformTest, Operator) {
        EXPECT_EQ(RotationMatrix::identity() * Vector3::ones(),
                  Vector3::ones() * RotationMatrix::identity());
    }
}
