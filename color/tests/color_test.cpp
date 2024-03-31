#include "color.hpp"
#include <gtest/gtest.h>

TEST(ColorTest, HandlesDefaultConstruction) {
  Color::RGBA rgba{};
  EXPECT_EQ(rgba.getRed(), 0.0)
      << "Color::RGBA red value not initialized to 0.0";
  EXPECT_EQ(rgba.getGreen(), 0.0)
      << "Color::RGBA green value not initialized to 0.0";
  EXPECT_EQ(rgba.getBlue(), 0.0)
      << "Color::RGBA blue value not initialized to 0.0";
  EXPECT_EQ(rgba.getAlpha(), 0.0)
      << "Color::RGBA alpha value not initialized to 0.0";
}
TEST(ColorTest, HandlesInRangeConstruction) {
  constexpr float val{0.5};
  Color::RGBA rgba(val, val, val, val);
  EXPECT_EQ(rgba.getRed(), val)
      << "Color::RGBA red value not initialized to in-range val";
  EXPECT_EQ(rgba.getGreen(), val)
      << "Color::RGBA green value not initialized to in-range val";
  EXPECT_EQ(rgba.getBlue(), val)
      << "Color::RGBA blue value not initialized to in-range val";
  EXPECT_EQ(rgba.getAlpha(), val)
      << "Color::RGBA alpha value not initialized to in-range val";
}
TEST(ColorTest, HandlesOverRangeConstruction) {
  Color::RGBA rgba(300.0, 300.0, 300.0, 300.0);
  EXPECT_EQ(rgba.getRed(), 1.0) << "Color::RGBA red value did not clamp to 1.0";
  EXPECT_EQ(rgba.getGreen(), 1.0)
      << "Color::RGBA green value did not clamp to 1.0";
  EXPECT_EQ(rgba.getBlue(), 1.0)
      << "Color::RGBA blue value did not clamp to 1.0";
  EXPECT_EQ(rgba.getAlpha(), 1.0)
      << "Color::RGBA alpha value did not clamp to 1.0";
}
TEST(ColorTest, HandlesUnderRangeConstruction) {
  Color::RGBA rgba(-300.0, -300.0, -300.0, -300.0);
  EXPECT_EQ(rgba.getRed(), 0.0) << "Color::RGBA red value did not clamp to 0.0";
  EXPECT_EQ(rgba.getGreen(), 0.0)
      << "Color::RGBA green value did not clamp to 0.0";
  EXPECT_EQ(rgba.getBlue(), 0.0)
      << "Color::RGBA blue value did not clamp to 0.0";
  EXPECT_EQ(rgba.getAlpha(), 0.0)
      << "Color::RGBA alpha value did not clamp to 0.0";
}
