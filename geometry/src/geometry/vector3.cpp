#include "vector3.hpp"
#include <cassert>
#include <cmath>
#include <type_traits>

namespace Geometry {

template <typename T> T Vector3<T>::length() const {
  static_assert(std::is_floating_point_v<T>,
                "Vector3::length() is only supported for floating point types");

  return std::sqrt(dot(*this));
}

template <typename T> Vector3<T> Vector3<T>::normalized() const {
  static_assert(
      std::is_floating_point_v<T>,
      "Vector3::normalized() is only supported for floating point types");
  assert(*this != Vector3<T>() &&
         "Vector3::normalized() cannot normalize a zero vector");

  return (*this) / length();
}

} // namespace Geometry

template class Geometry::Vector3<float>;
