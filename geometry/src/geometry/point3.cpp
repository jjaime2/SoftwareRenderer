#include "point3.hpp"

namespace Geometry {

template <typename T> T Point3<T>::distanceTo(const Point3<T> &other) const {
  Vector3<T> diff = *this - other;
  return diff.length();
}
} // namespace Geometry

template class Geometry::Point3<int>;
