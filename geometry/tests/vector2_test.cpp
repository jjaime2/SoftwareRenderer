#include "vector2.hpp"
#include "gtest/gtest.h"
#include <gtest/gtest.h>
#include <type_traits>

template <typename T> class Vector2Test : public testing::Test {
protected:
  void SetUp() override {}
};

using Vector2Types = ::testing::Types<int, float>;
TYPED_TEST_SUITE(Vector2Test, Vector2Types);

TYPED_TEST(Vector2Test, HandlesDefaultConstruction) {
  Geometry::Vector2<TypeParam> zeroVector{};
  if constexpr (std::is_integral_v<TypeParam>) {
    EXPECT_EQ(zeroVector.x, 0);
    EXPECT_EQ(zeroVector.y, 0);
  } else if (std::is_floating_point_v<TypeParam>) {
    EXPECT_FLOAT_EQ(zeroVector.x, 0.0f);
    EXPECT_FLOAT_EQ(zeroVector.y, 0.0f);
  }
}

TYPED_TEST(Vector2Test, HandlesFillConstruction) {
  Geometry::Vector2<TypeParam> fillVector(1);
  if constexpr (std::is_integral_v<TypeParam>) {
    EXPECT_EQ(fillVector.x, 1);
    EXPECT_EQ(fillVector.y, 1);
  } else if (std::is_floating_point_v<TypeParam>) {
    EXPECT_FLOAT_EQ(fillVector.x, 1.0f);
    EXPECT_FLOAT_EQ(fillVector.y, 1.0f);
  }
}

TYPED_TEST(Vector2Test, HandlesCoordinateConstruction) {
  Geometry::Vector2<TypeParam> coordinateVector(1, 2);
  if constexpr (std::is_integral_v<TypeParam>) {
    EXPECT_EQ(coordinateVector.x, 1);
    EXPECT_EQ(coordinateVector.y, 2);
  } else if (std::is_floating_point_v<TypeParam>) {
    EXPECT_FLOAT_EQ(coordinateVector.x, 1.0f);
    EXPECT_FLOAT_EQ(coordinateVector.y, 2.0f);
  }
}

TYPED_TEST(Vector2Test, HandlesConversionConstruction) {
  Geometry::Vec2f floatVector(1.0f, 2.0f);
  Geometry::Vec2i intVector(floatVector);
  EXPECT_EQ(intVector.x, static_cast<int>(floatVector.x));
  EXPECT_EQ(intVector.y, static_cast<int>(floatVector.y));
}

TYPED_TEST(Vector2Test, HandlesLengthAndNorm) {
  Geometry::Vec2f vector(1, 2);
  EXPECT_FLOAT_EQ(vector.lengthSquared(), 5.0f);
  EXPECT_FLOAT_EQ(vector.length(), 2.236068f);
  EXPECT_FLOAT_EQ(vector.normalized().length(), 1.0f);
}

TYPED_TEST(Vector2Test, HandlesDotProduct) {
  Geometry::Vector2<TypeParam> vector(1, 2);
  if constexpr (std::is_integral_v<TypeParam>) {
    EXPECT_EQ(vector.dot(vector), 5);
  } else if (std::is_floating_point_v<TypeParam>) {
    EXPECT_FLOAT_EQ(vector.dot(vector), 5.0f);
  }
}

TYPED_TEST(Vector2Test, HandlesCrossProduct) {
  Geometry::Vector2<TypeParam> vector(1, 2);
  Geometry::Vector2<TypeParam> crossVector{vector.cross(vector)};
  if constexpr (std::is_integral_v<TypeParam>) {
    EXPECT_EQ(crossVector.x, 0);
    EXPECT_EQ(crossVector.y, 0);
  } else if (std::is_floating_point_v<TypeParam>) {
    EXPECT_FLOAT_EQ(crossVector.x, 0.0f);
    EXPECT_FLOAT_EQ(crossVector.y, 0.0f);
  }
}

// TODO: Add more tests for vector operators
