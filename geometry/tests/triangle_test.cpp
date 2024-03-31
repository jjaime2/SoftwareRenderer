#include "color.hpp"
#include "geometry.hpp"
#include <gtest/gtest.h>

TEST(TriangleTest, HandlesNonDefaultConstruction) {
  Color::RGBA color(1.0, 0.0, 0.0, 1.0);
  Geometry::Pnt3f p1(0.0f, 0.0f, 0.0f);
  Geometry::Pnt3f p2(1.0f, 0.0f, 0.0f);
  Geometry::Pnt3f p3(0.0f, 1.0f, 0.0f);
}
