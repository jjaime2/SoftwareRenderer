#pragma once

namespace Geometry {

template <typename T> class Vector2 {
public:
  T x{};
  T y{};

  // Constructors
  constexpr Vector2();
  constexpr Vector2(T f);
  constexpr Vector2(T x, T y);
  template <typename U> constexpr explicit Vector2(const Vector2<U> &v);

  // Member functions
  constexpr T lengthSquared() const;
  T length() const;
  Vector2<T> normalized() const;
  constexpr T dot(const Vector2<T> &right) const;
  constexpr T cross(const Vector2<T> &right) const;
};

/**
 * Overload of unary operator -
 *
 * @param left: Left Vector2 operand
 * @return: The negation of left
 */
template <typename T>
[[nodiscard]] constexpr Vector2<T> operator-(const Vector2<T> &left);

/**
 * Overload of binary operator +
 *
 * @param left: Left Vector2 operand
 * @param right: Right Vector2 operand
 * @return: Memberwise addition of both vectors
 */
template <typename T>
[[nodiscard]] constexpr Vector2<T> operator+(const Vector2<T> &left,
                                             const Vector2<T> &right);

/**
 * Overload of binary operator -
 *
 * @param left: Left Vector2 operand
 * @param right: Right Vector2 operand
 * @return: Memberwise subtraction of both vectors
 */
template <typename T>
[[nodiscard]] constexpr Vector2<T> operator-(const Vector2<T> &left,
                                             const Vector2<T> &right);

/**
 * Overload of binary operator *
 *
 * @param left: Left scalar operand
 * @param right: Right Vector2 operand
 * @return: Memberwise multiplication by right
 */
template <typename T>
[[nodiscard]] constexpr Vector2<T> operator*(T left, const Vector2<T> &right);

/**
 * Overload of binary operator *
 *
 * @param left: Left Vector2 operand
 * @param right: Right scalar operand
 * @return: Memberwise multiplication by left
 */
template <typename T>
[[nodiscard]] constexpr Vector2<T> operator*(const Vector2<T> &left, T right);

/**
 * Overload of binary operator /
 *
 * @param left: Left Vector2 operand
 * @param right: Right scalar operand
 * @return: Memberwise division by right
 */
template <typename T>
[[nodiscard]] constexpr Vector2<T> operator/(const Vector2<T> &left, T right);

/**
 * Overload of binary operator ==
 *
 * @param left: Left Vector2 operand
 * @param right: Right Vector2 operand
 * @return: True if left is equal to right
 */
template <typename T>
[[nodiscard]] constexpr bool operator==(const Vector2<T> &left,
                                        const Vector2<T> &right);

/**
 * Overload of binary operator !=
 *
 * @param left: Left Vector2 operand
 * @param right: Right Vector2 operand
 * @return: True if left is not equal to right
 */
template <typename T>
[[nodiscard]] constexpr bool operator!=(const Vector2<T> &left,
                                        const Vector2<T> &right);

/**
 * Overload of binary operator +=
 *
 * Performs memberwise addition of both vectors and assigns the result to left
 *
 * @param left: Left Vector2 operand
 * @param right: Right Vector2 operand
 * @return: Reference to left
 */
template <typename T>
constexpr Vector2<T> &operator+=(const Vector2<T> &left,
                                 const Vector2<T> &right);

/**
 * Overload of binary operator -=
 *
 * Performs memberwise subtraction of both vectors and assigns the result to
 * left
 *
 * @param left: Left Vector2 operand
 * @param right: Right Vector2 operand
 * @return: Reference to left
 */
template <typename T>
constexpr Vector2<T> &operator-=(const Vector2<T> &left,
                                 const Vector2<T> &right);

/**
 * Overload of binary operator *=
 *
 * Performs memberwise multiplication of vector left by scalar right and assigns
 * result to left
 *
 * @param left: Left Vector2 operand
 * @param right: Right scalar operand
 * @return: Reference to left
 */
template <typename T>
constexpr Vector2<T> &operator*=(const Vector2<T> &left, T right);

/**
 * Overload of binary operator /=
 *
 * Performs memberwise division of vector left by scalar right and assigns
 * result to left
 *
 * @param left: Left Vector2 operand
 * @param right: Right scalar operand
 * @return: Reference to left
 */
template <typename T>
constexpr Vector2<T> &operator/=(const Vector2<T> &left, T right);

using Vec2f = Vector2<float>;
using Vec2i = Vector2<int>;
} // namespace Geometry

#include "vector2.inl"
