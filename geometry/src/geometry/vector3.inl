#include "vector3.hpp"

namespace Geometry {

template <typename T> constexpr Vector3<T>::Vector3() = default;

template <typename T>
constexpr Vector3<T>::Vector3(T x, T y, T z) : x(x), y(y), z(z) {}

template <typename T> constexpr Vector3<T>::Vector3(T f) : x(f), y(f), z(f) {}

template <typename T>
template <typename U>
constexpr Vector3<T>::Vector3(const Vector3<U> &v)
    : x(static_cast<T>(v.x)), y(static_cast<T>(v.y)), z(static_cast<T>(v.z)) {}

template <typename T> constexpr T Vector3<T>::lengthSquared() const {
  return dot(*this);
}

template <typename T>
constexpr T Vector3<T>::dot(const Vector3<T> &right) const {
  return x * right.x + y * right.y + z * right.z;
}

template <typename T>
constexpr Vector3<T> Vector3<T>::cross(const Vector3<T> &right) const {
  return Vector3<T>((y * right.z) - (z * right.y),
                    (z * right.x) - (x * right.z),
                    (x * right.y) - (y * right.x));
}

template <typename T> constexpr Vector3<T> operator-(const Vector3<T> &left) {
  return Vector3<T>(-1 * left.x, -1 * left.y, -1 * left.z);
}

template <typename T>
constexpr Vector3<T> operator+(const Vector3<T> &left,
                               const Vector3<T> &right) {
  return Vector3<T>(left.x + right.x, left.y + right.y, left.z + right.z);
}

template <typename T>
constexpr Vector3<T> operator-(const Vector3<T> &left,
                               const Vector3<T> &right) {
  return Vector3<T>(left.x - right.x, left.y - right.y, left.z - right.z);
}

template <typename T>
constexpr Vector3<T> operator*(T left, const Vector3<T> &right) {
  return Vector3<T>(left * right.x, left * right.y, left * right.z);
}

template <typename T>
constexpr Vector3<T> operator*(const Vector3<T> &left, T right) {
  return Vector3<T>(left.x * right, left.y * right, left.z * right);
}

template <typename T>
constexpr Vector3<T> operator/(const Vector3<T> &left, T right) {
  return Vector3<T>(left.x / right, left.y / right, left.z / right);
}

template <typename T>
constexpr bool operator==(const Vector3<T> &left, const Vector3<T> &right) {
  return (left.x == right.x) && (left.y == right.y) && (left.z == right.z);
}

template <typename T>
constexpr bool operator!=(const Vector3<T> &left, const Vector3<T> &right) {
  return (left.x != right.x) || (left.y != right.y) || (left.z != right.z);
}

template <typename T>
constexpr Vector3<T> &operator+=(const Vector3<T> &left,
                                 const Vector3<T> &right) {
  left.x += right.x;
  left.y += right.y;
  left.z += right.z;

  return left;
}

template <typename T>
constexpr Vector3<T> &operator-=(const Vector3<T> &left,
                                 const Vector3<T> &right) {
  left.x -= right.x;
  left.y -= right.y;
  left.z -= right.z;

  return left;
}

template <typename T>
constexpr Vector3<T> &operator*=(const Vector3<T> &left, T right) {
  left.x *= right;
  left.y *= right;
  left.z *= right;

  return left;
}

template <typename T>
constexpr Vector3<T> &operator/=(const Vector3<T> &left, T right) {
  left.x /= right;
  left.y /= right;
  left.z /= right;

  return left;
}
} // namespace Geometry
