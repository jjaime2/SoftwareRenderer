#include "geometry.hpp"
#include <gtest/gtest.h>

TEST(Point3DTest, HandlesDistanceTo) {
  Geometry::Pnt3f p1(1.0f, 1.0f, 0.0f);
  Geometry::Pnt3f p2(1.0f, 1.0f, 1.0f);
  EXPECT_FLOAT_EQ(p1.distanceTo(p2), 1.0f);
}
