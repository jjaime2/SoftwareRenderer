#include "vector2.hpp"
#include <cassert>
#include <cmath>
#include <type_traits>

namespace Geometry {

template <typename T> T Vector2<T>::length() const {
  static_assert(std::is_floating_point_v<T>,
                "Vector2::length() is only supported for floating point types");

  return std::sqrt(dot(*this));
}

template <typename T> Vector2<T> Vector2<T>::normalized() const {
  static_assert(
      std::is_floating_point_v<T>,
      "Vector2::normalized() is only supported for floating point types");
  assert(*this != Vector2<T>() &&
         "Vector2::normalized() cannot normalize a zero vector");

  return (*this) / length();
}

} // namespace Geometry

template class Geometry::Vector2<float>;
