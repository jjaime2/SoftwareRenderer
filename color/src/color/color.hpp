#ifndef COLOR_HPP
#define COLOR_HPP

#include <cmath>
#include <ostream>

namespace Color {
class RGBA {
private:
  float r;
  float g;
  float b;
  float a;

  void clamp() {
    r = std::fmax(std::fmin(r, 1.0f), 0.0f);
    g = std::fmax(std::fmin(g, 1.0f), 0.0f);
    b = std::fmax(std::fmin(b, 1.0f), 0.0f);
    a = std::fmax(std::fmin(a, 1.0f), 0.0f);
  }

public:
  RGBA();
  RGBA(float red, float green, float blue, float alpha);

  float getRed() const { return r; }
  float getGreen() const { return g; }
  float getBlue() const { return b; }
  float getAlpha() const { return a; }

  friend std::ostream &operator<<(std::ostream &os, RGBA &rgba) {
    return os << "[" << rgba.r << ", " << rgba.g << ", " << rgba.b << ", "
              << rgba.a << "]";
  }
};
} // namespace Color
#endif
