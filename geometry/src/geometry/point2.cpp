#include "point2.hpp"
#include <cstdint>

namespace Geometry {

template <typename T> T Point2<T>::distanceTo(const Point2<T> &other) const {
  Vector2<T> diff = *this - other;
  return diff.length();
}
} // namespace Geometry

template class Geometry::Point2<int>;
template class Geometry::Point2<uint32_t>;
