#include "geometry.hpp"
#include <gtest/gtest.h>
#include <limits>

TEST(BoundingBoxTest, HandlesDefaultConstruction) {
  Geometry::BBox3f bbox{};
  Geometry::Pnt3f min{bbox.getMin()};
  Geometry::Pnt3f max{bbox.getMax()};
  EXPECT_FLOAT_EQ(min.getX(), std::numeric_limits<float>::max());
  EXPECT_FLOAT_EQ(min.getY(), std::numeric_limits<float>::max());
  EXPECT_FLOAT_EQ(min.getZ(), std::numeric_limits<float>::max());
  EXPECT_FLOAT_EQ(max.getZ(), std::numeric_limits<float>::min());
  EXPECT_FLOAT_EQ(max.getZ(), std::numeric_limits<float>::min());
  EXPECT_FLOAT_EQ(max.getZ(), std::numeric_limits<float>::min());
}

TEST(BoundingBoxTest, HandlesNonDefaultConstruction) {
  Geometry::Pnt3f min(1.0f, 2.0f, 3.0f);
  Geometry::Pnt3f max(4.0f, 5.0f, 6.0f);
  Geometry::BBox3f bbox(min, max);
  EXPECT_FLOAT_EQ(bbox.getMin().getX(), 1.0f);
  EXPECT_FLOAT_EQ(bbox.getMin().getY(), 2.0f);
  EXPECT_FLOAT_EQ(bbox.getMin().getZ(), 3.0f);
  EXPECT_FLOAT_EQ(bbox.getMax().getX(), 4.0f);
  EXPECT_FLOAT_EQ(bbox.getMax().getY(), 5.0f);
  EXPECT_FLOAT_EQ(bbox.getMax().getZ(), 6.0f);
}

TEST(BoundingBoxTest, HandlesContainsInRange) {
  Geometry::Pnt3f min(1.0f, 2.0f, 3.0f);
  Geometry::Pnt3f max(4.0f, 5.0f, 6.0f);
  Geometry::Pnt3f p(2.0f, 3.0f, 4.0f);
  Geometry::BBox3f bbox(min, max);
  EXPECT_TRUE(bbox.contains(p));
}

TEST(BoundingBoxTest, HandlesContainsOutOfRange) {
  Geometry::Pnt3f min(1.0f, 2.0f, 3.0f);
  Geometry::Pnt3f max(4.0f, 5.0f, 6.0f);
  Geometry::Pnt3f p(0.0f, 0.0f, 0.0f);
  Geometry::BBox3f bbox(min, max);
  EXPECT_TRUE(!bbox.contains(p));
}

TEST(BoundingBoxTest, HandlesContainsCloseToThreshold) {
  Geometry::Pnt3f min(1.0f, 2.0f, 3.0f);
  Geometry::Pnt3f max(4.0f, 5.0f, 6.0f);
  Geometry::Pnt3f p(0.99f, 1.99f, 2.99f);
  Geometry::BBox3f bbox(min, max);
  EXPECT_TRUE(!bbox.contains(p));
}

TEST(BoundingBoxTest, HandlesGetDimensions) {
  Geometry::Pnt3f min(1.0f, 2.0f, 3.0f);
  Geometry::Pnt3f max(4.0f, 5.0f, 6.0f);
  Geometry::BBox3f bbox(min, max);
  EXPECT_FLOAT_EQ(bbox.getWidth(), 3.0f);
  EXPECT_FLOAT_EQ(bbox.getHeight(), 3.0f);
  EXPECT_FLOAT_EQ(bbox.getDepth(), 3.0f);
  EXPECT_FLOAT_EQ(bbox.getCenter().getX(), 2.5f);
  EXPECT_FLOAT_EQ(bbox.getCenter().getY(), 3.5f);
  EXPECT_FLOAT_EQ(bbox.getCenter().getZ(), 4.5f);
  EXPECT_FLOAT_EQ(bbox.getVolume(), 3.0f * 3.0f * 3.0f);
}
