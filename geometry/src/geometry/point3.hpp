#include "vector3.hpp"

namespace Geometry {

template <typename T> class Point3 : public Vector3<T> {
public:
  T distanceTo(const Point3 &other) const;
};

using Pnt3i = Point3<int>;
} // namespace Geometry
