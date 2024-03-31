#pragma once

namespace Geometry {

template <typename T> class Vector3 {
public:
  T x{};
  T y{};
  T z{};

  // Constructors
  constexpr Vector3();
  constexpr Vector3(T f);
  constexpr Vector3(T x, T y, T z);
  template <typename U> constexpr explicit Vector3(const Vector3<U> &v);

  // Member functions
  constexpr T lengthSquared() const;
  T length() const;
  Vector3<T> normalized() const;
  constexpr T dot(const Vector3<T> &right) const;
  constexpr Vector3<T> cross(const Vector3<T> &right) const;
};

/**
 * Overload of unary operator -
 *
 * @param left: Left Vector3 operand
 * @return: The negation of left
 */
template <typename T>
[[nodiscard]] constexpr Vector3<T> operator-(const Vector3<T> &left);

/**
 * Overload of binary operator +
 *
 * @param left: Left Vector3 operand
 * @param right: Right Vector3 operand
 * @return: Memberwise addition of both vectors
 */
template <typename T>
[[nodiscard]] constexpr Vector3<T> operator+(const Vector3<T> &left,
                                             const Vector3<T> &right);

/**
 * Overload of binary operator -
 *
 * @param left: Left Vector3 operand
 * @param right: Right Vector3 operand
 * @return: Memberwise subtraction of both vectors
 */
template <typename T>
[[nodiscard]] constexpr Vector3<T> operator-(const Vector3<T> &left,
                                             const Vector3<T> &right);

/**
 * Overload of binary operator *
 *
 * @param left: Left scalar operand
 * @param right: Right Vector3 operand
 * @return: Memberwise multiplication by right
 */
template <typename T>
[[nodiscard]] constexpr Vector3<T> operator*(T left, const Vector3<T> &right);

/**
 * Overload of binary operator *
 *
 * @param left: Left Vector3 operand
 * @param right: Right scalar operand
 * @return: Memberwise multiplication by left
 */
template <typename T>
[[nodiscard]] constexpr Vector3<T> operator*(const Vector3<T> &left, T right);

/**
 * Overload of binary operator /
 *
 * @param left: Left Vector3 operand
 * @param right: Right scalar operand
 * @return: Memberwise division by right
 */
template <typename T>
[[nodiscard]] constexpr Vector3<T> operator/(const Vector3<T> &left, T right);

/**
 * Overload of binary operator ==
 *
 * @param left: Left Vector3 operand
 * @param right: Right Vector3 operand
 * @return: True if left is equal to right
 */
template <typename T>
[[nodiscard]] constexpr bool operator==(const Vector3<T> &left,
                                        const Vector3<T> &right);

/**
 * Overload of binary operator !=
 *
 * @param left: Left Vector3 operand
 * @param right: Right Vector3 operand
 * @return: True if left is not equal to right
 */
template <typename T>
[[nodiscard]] constexpr bool operator!=(const Vector3<T> &left,
                                        const Vector3<T> &right);

/**
 * Overload of binary operator +=
 *
 * Performs memberwise addition of both vectors and assigns the result to left
 *
 * @param left: Left Vector3 operand
 * @param right: Right Vector3 operand
 * @return: Reference to left
 */
template <typename T>
constexpr Vector3<T> &operator+=(const Vector3<T> &left,
                                 const Vector3<T> &right);

/**
 * Overload of binary operator -=
 *
 * Performs memberwise subtraction of both vectors and assigns the result to
 * left
 *
 * @param left: Left Vector3 operand
 * @param right: Right Vector3 operand
 * @return: Reference to left
 */
template <typename T>
constexpr Vector3<T> &operator-=(const Vector3<T> &left,
                                 const Vector3<T> &right);

/**
 * Overload of binary operator *=
 *
 * Performs memberwise multiplication of vector left by scalar right and assigns
 * result to left
 *
 * @param left: Left Vector3 operand
 * @param right: Right scalar operand
 * @return: Reference to left
 */
template <typename T>
constexpr Vector3<T> &operator*=(const Vector3<T> &left, T right);

/**
 * Overload of binary operator /=
 *
 * Performs memberwise division of vector left by scalar right and assigns
 * result to left
 *
 * @param left: Left Vector3 operand
 * @param right: Right scalar operand
 * @return: Reference to left
 */
template <typename T>
constexpr Vector3<T> &operator/=(const Vector3<T> &left, T right);

using Vec3f = Vector3<float>;
using Vec3i = Vector3<int>;
} // namespace Geometry

#include "vector3.inl"
