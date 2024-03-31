#include "vector2.hpp"

namespace Geometry {

template <typename T> constexpr Vector2<T>::Vector2() = default;

template <typename T> constexpr Vector2<T>::Vector2(T x, T y) : x(x), y(y) {}

template <typename T> constexpr Vector2<T>::Vector2(T f) : x(f), y(f) {}

template <typename T>
template <typename U>
constexpr Vector2<T>::Vector2(const Vector2<U> &v)
    : x(static_cast<T>(v.x)), y(static_cast<T>(v.y)) {}

template <typename T> constexpr T Vector2<T>::lengthSquared() const {
  return dot(*this);
}

template <typename T>
constexpr T Vector2<T>::dot(const Vector2<T> &right) const {
  return x * right.x + y * right.y;
}

template <typename T>
constexpr T Vector2<T>::cross(const Vector2<T> &right) const {
  return x * right.y - y * right.x;
}

template <typename T> constexpr Vector2<T> operator-(const Vector2<T> &left) {
  return Vector2<T>(-1 * left.x, -1 * left.y);
}

template <typename T>
constexpr Vector2<T> operator+(const Vector2<T> &left,
                               const Vector2<T> &right) {
  return Vector2<T>(left.x + right.x, left.y + right.y);
}

template <typename T>
constexpr Vector2<T> operator-(const Vector2<T> &left,
                               const Vector2<T> &right) {
  return Vector2<T>(left.x - right.x, left.y - right.y);
}

template <typename T>
constexpr Vector2<T> operator*(T left, const Vector2<T> &right) {
  return Vector2<T>(left * right.x, left * right.y);
}

template <typename T>
constexpr Vector2<T> operator*(const Vector2<T> &left, T right) {
  return Vector2<T>(left.x * right, left.y * right);
}

template <typename T>
constexpr Vector2<T> operator/(const Vector2<T> &left, T right) {
  return Vector2<T>(left.x / right, left.y / right);
}

template <typename T>
constexpr bool operator==(const Vector2<T> &left, const Vector2<T> &right) {
  return (left.x == right.x) && (left.y == right.y);
}

template <typename T>
constexpr bool operator!=(const Vector2<T> &left, const Vector2<T> &right) {
  return (left.x != right.x) || (left.y != right.y);
}

template <typename T>
constexpr Vector2<T> &operator+=(const Vector2<T> &left,
                                 const Vector2<T> &right) {
  left.x += right.x;
  left.y += right.y;

  return left;
}

template <typename T>
constexpr Vector2<T> &operator-=(const Vector2<T> &left,
                                 const Vector2<T> &right) {
  left.x -= right.x;
  left.y -= right.y;

  return left;
}

template <typename T>
constexpr Vector2<T> &operator*=(const Vector2<T> &left, T right) {
  left.x *= right;
  left.y *= right;

  return left;
}

template <typename T>
constexpr Vector2<T> &operator/=(const Vector2<T> &left, T right) {
  left.x /= right;
  left.y /= right;

  return left;
}
} // namespace Geometry
