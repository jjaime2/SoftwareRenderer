#ifndef COLOR_HPP
#define COLOR_HPP

#include <ostream>

namespace Color {

class RGBA {
private:
  std::uint8_t r;
  std::uint8_t g;
  std::uint8_t b;
  std::uint8_t a;

public:
  RGBA();
  RGBA(std::uint8_t red, std::uint8_t green, std::uint8_t blue);
  RGBA(std::uint8_t red, std::uint8_t green, std::uint8_t blue,
       std::uint8_t alpha);

  std::uint8_t getRed() const { return r; }
  std::uint8_t getGreen() const { return g; }
  std::uint8_t getBlue() const { return b; }
  std::uint8_t getAlpha() const { return a; }

  friend std::ostream &operator<<(std::ostream &os, RGBA &rgba) {
    return os << "[" << static_cast<int>(rgba.r) << ", "
              << static_cast<int>(rgba.g) << ", " << static_cast<int>(rgba.b)
              << ", " << static_cast<int>(rgba.a) << "]";
  }
};
} // namespace Color
#endif
