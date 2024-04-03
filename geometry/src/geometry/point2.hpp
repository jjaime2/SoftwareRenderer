#include "vector2.hpp"
#include <cstdint>

namespace Geometry {

template <typename T> class Point2 : public Vector2<T> {
public:
  T distanceTo(const Point2 &other) const;
};

using Pnt2i = Point2<int>;
using Pnt2u = Point2<uint32_t>;
} // namespace Geometry
