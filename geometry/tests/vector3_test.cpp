#include "vector3.hpp"
#include "gtest/gtest.h"
#include <gtest/gtest.h>
#include <type_traits>

template <typename T> class Vector3Test : public testing::Test {
protected:
  void SetUp() override {}
};

using Vector3Types = ::testing::Types<int, float>;
TYPED_TEST_SUITE(Vector3Test, Vector3Types);

TYPED_TEST(Vector3Test, HandlesDefaultConstruction) {
  Geometry::Vector3<TypeParam> zeroVector{};
  if constexpr (std::is_integral_v<TypeParam>) {
    EXPECT_EQ(zeroVector.x, 0);
    EXPECT_EQ(zeroVector.y, 0);
    EXPECT_EQ(zeroVector.z, 0);
  } else if (std::is_floating_point_v<TypeParam>) {
    EXPECT_FLOAT_EQ(zeroVector.x, 0.0f);
    EXPECT_FLOAT_EQ(zeroVector.y, 0.0f);
    EXPECT_FLOAT_EQ(zeroVector.z, 0.0f);
  }
}

TYPED_TEST(Vector3Test, HandlesFillConstruction) {
  Geometry::Vector3<TypeParam> fillVector(1);
  if constexpr (std::is_integral_v<TypeParam>) {
    EXPECT_EQ(fillVector.x, 1);
    EXPECT_EQ(fillVector.y, 1);
    EXPECT_EQ(fillVector.z, 1);
  } else if (std::is_floating_point_v<TypeParam>) {
    EXPECT_FLOAT_EQ(fillVector.x, 1.0f);
    EXPECT_FLOAT_EQ(fillVector.y, 1.0f);
    EXPECT_FLOAT_EQ(fillVector.z, 1.0f);
  }
}

TYPED_TEST(Vector3Test, HandlesCoordinateConstruction) {
  Geometry::Vector3<TypeParam> coordinateVector(1, 2, 3);
  if constexpr (std::is_integral_v<TypeParam>) {
    EXPECT_EQ(coordinateVector.x, 1);
    EXPECT_EQ(coordinateVector.y, 2);
    EXPECT_EQ(coordinateVector.z, 3);
  } else if (std::is_floating_point_v<TypeParam>) {
    EXPECT_FLOAT_EQ(coordinateVector.x, 1.0f);
    EXPECT_FLOAT_EQ(coordinateVector.y, 2.0f);
    EXPECT_FLOAT_EQ(coordinateVector.z, 3.0f);
  }
}

TYPED_TEST(Vector3Test, HandlesConversionConstruction) {
  Geometry::Vec3f floatVector(1.0f, 2.0f, 3.0f);
  Geometry::Vec3i intVector(floatVector);
  EXPECT_EQ(intVector.x, static_cast<int>(floatVector.x));
  EXPECT_EQ(intVector.y, static_cast<int>(floatVector.y));
  EXPECT_EQ(intVector.z, static_cast<int>(floatVector.z));
}

TYPED_TEST(Vector3Test, HandlesLengthAndNorm) {
  Geometry::Vec3f vector(1, 2, 3);
  EXPECT_FLOAT_EQ(vector.lengthSquared(), 14.0f);
  EXPECT_FLOAT_EQ(vector.length(), 3.7416575f);
  EXPECT_FLOAT_EQ(vector.normalized().length(), 1.0f);
}

TYPED_TEST(Vector3Test, HandlesDotProduct) {
  Geometry::Vector3<TypeParam> vector(1, 2, 3);
  if constexpr (std::is_integral_v<TypeParam>) {
    EXPECT_EQ(vector.dot(vector), 14);
  } else if (std::is_floating_point_v<TypeParam>) {
    EXPECT_FLOAT_EQ(vector.dot(vector), 14.0f);
  }
}

TYPED_TEST(Vector3Test, HandlesCrossProduct) {
  Geometry::Vector3<TypeParam> vector(1, 2, 3);
  Geometry::Vector3<TypeParam> crossVector{vector.cross(vector)};
  if constexpr (std::is_integral_v<TypeParam>) {
    EXPECT_EQ(crossVector.x, 0);
    EXPECT_EQ(crossVector.y, 0);
    EXPECT_EQ(crossVector.z, 0);
  } else if (std::is_floating_point_v<TypeParam>) {
    EXPECT_FLOAT_EQ(crossVector.x, 0.0f);
    EXPECT_FLOAT_EQ(crossVector.y, 0.0f);
    EXPECT_FLOAT_EQ(crossVector.z, 0.0f);
  }
}

// TODO: Add more tests for vector operators
