#include "color.hpp"

namespace Color {

RGBA::RGBA() : r(0), g(0), b(0), a(0) {}

RGBA::RGBA(std::uint8_t red, std::uint8_t green, std::uint8_t blue)
    : r(red), g(green), b(blue), a(255) {}

RGBA::RGBA(std::uint8_t red, std::uint8_t green, std::uint8_t blue,
           std::uint8_t alpha)
    : r(red), g(green), b(blue), a(alpha) {}
} // namespace Color
