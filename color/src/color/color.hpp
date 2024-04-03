#ifndef COLOR_HPP
#define COLOR_HPP

#include "common.hpp"
#include <cmath>
#include <ostream>
#include <type_traits>

namespace Color {

template <typename T> class RGBA {
private:
  T r;
  T g;
  T b;
  T a;

  void clamp() {
    r = Common::max(Common::min(r, static_cast<T>(1)), static_cast<T>(0));
    g = Common::max(Common::min(g, static_cast<T>(1)), static_cast<T>(0));
    b = Common::max(Common::min(b, static_cast<T>(1)), static_cast<T>(0));
    a = Common::max(Common::min(a, static_cast<T>(1)), static_cast<T>(0));
  }

public:
  RGBA();
  RGBA(T red, T green, T blue);
  RGBA(T red, T green, T blue, T alpha);

  T getRed() const { return r; }
  T getGreen() const { return g; }
  T getBlue() const { return b; }
  T getAlpha() const { return a; }

  friend std::ostream &operator<<(std::ostream &os, RGBA &rgba) {
    return os << "[" << rgba.r << ", " << rgba.g << ", " << rgba.b << ", "
              << rgba.a << "]";
  }
};

using RGBAf = RGBA<float>;
using RGBAu = RGBA<uint8_t>;
} // namespace Color
#endif
