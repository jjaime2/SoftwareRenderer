#include "vector2.hpp"

namespace Geometry {

template <typename T> class Point2 : public Vector2<T> {
public:
  T distanceTo(const Point2 &other) const;
};

using Pnt2i = Point2<int>;
} // namespace Geometry
