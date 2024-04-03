#include "color.hpp"

namespace Color {

template <typename T>
RGBA<T>::RGBA()
    : r(static_cast<T>(0)), g(static_cast<T>(0)), b(static_cast<T>(0)),
      a(static_cast<T>(0)) {}

template <typename T>
RGBA<T>::RGBA(T red, T green, T blue)
    : r(red), g(green), b(blue), a(static_cast<T>(1)) {
  clamp();
}

template <typename T>
RGBA<T>::RGBA(T red, T green, T blue, T alpha)
    : r(red), g(green), b(blue), a(alpha) {
  clamp();
}
} // namespace Color

template class Color::RGBA<float>;
template class Color::RGBA<uint8_t>;
