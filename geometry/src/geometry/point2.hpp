#pragma once

#include "vector2.hpp"
#include <cstdint>

namespace Geometry {

template <typename T> class Point2 : public Vector2<T> {
public:
  using Vector2<T>::Vector2;
  T distanceTo(const Point2<T> &other) const;
};

using Pnt2i = Point2<int>;
using Pnt2u = Point2<uint32_t>;
} // namespace Geometry
