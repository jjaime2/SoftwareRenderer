#include "color.hpp"

Color::RGBA::RGBA() : r(0.0), g(0.0), b(0.0), a(0.0) {}
Color::RGBA::RGBA(float red, float green, float blue, float alpha)
    : r(red), g(green), b(blue), a(alpha) {
  clamp();
}
