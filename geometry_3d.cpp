/*
 * 3d Geometry Implementation.
 */

#include "geometry_3d.hpp"

#include <cmath>

using namespace std;

namespace Geometry {

namespace Three_Dimensional {

/***********************************************************************
 * Vector constructor
 *
 * Description:
 */
Vector::Vector()
  : _x(0.0),
    _y(0.0),
    _z(0.0) {
}

/***********************************************************************
 * Vector constructor
 *
 * Description:
 */
Vector::Vector(double x, double y, double z)
  : _x(x),
    _y(y),
    _z(z) {
}

/***********************************************************************
 * Vector Method: Vector additive assignment operator
 *
 * Description:
 */
Vector & Vector::operator+=(const Vector &rhs) {
    _x += rhs._x;
    _y += rhs._y;
    _z += rhs._z;
    return *this;
}

/***********************************************************************
 * Vector Method: Vector subtractive assignment operator
 *
 * Description:
 */
Vector & Vector::operator-=(const Vector &rhs) {
    _x -= rhs._x;
    _y -= rhs._y;
    _z -= rhs._z;
    return *this;
}

/***********************************************************************
 * Vector Method: Vector multiplicative assignment operator
 *
 * Description:
 */
Vector & Vector::operator*=(const double &rhs) {
    _x *= rhs;
    _y *= rhs;
    _z *= rhs;
    return *this;
}

/***********************************************************************
 * Vector Method: Vector subtractive assignment operator
 *
 * Description:
 */
Vector & Vector::operator/=(const double &rhs) {
    _x /= rhs;
    _y /= rhs;
    _z /= rhs;
    return *this;
}

/***********************************************************************
 * Vector Method: add operator
 *
 * Description:
 */
const Vector Vector::operator+(const Vector &other) const {
    return Vector(*this) += other;
}

/***********************************************************************
 * Vector Method: subtraction operator
 *
 * Description:
 */
const Vector Vector::operator-(const Vector &other) const {
    return Vector(*this) -= other;
}

/***********************************************************************
 * Vector Method: multiplication operator
 *
 * Description:
 */
const Vector Vector::operator*(const double &other) const {
    return Vector(*this) *= other;
}

/***********************************************************************
 * Vector Method: division operator
 *
 * Description:
 */
const Vector Vector::operator/(const double &other) const {
    return Vector(*this) /= other;
}

/***********************************************************************
 * Vector Method: cross product
 *
 * Description:
 */
Vector Vector::cross(const Vector &other) const {
    return Vector(_y * other._z - _z * other._y,
                  _z * other._x - _x * other._z,
                  _x * other._y - _y * other._x);
}

/***********************************************************************
 * Vector Method: dot product
 *
 * Description:
 */
const double Vector::dot(const Vector &other) const {
    return _x * other._x + _y * other._y + _z * other._z;
}

/***********************************************************************
 * Vector Method: magnitude2
 *
 * Description:
 */
const double Vector::magnitude2() const {
    return _x * _x + _y * _y + _z * _z;
}

/***********************************************************************
 * Vector Method: magnitude
 *
 * Description:
 */
const double Vector::magnitude() const {
    return sqrt(magnitude2());
}

/***********************************************************************
 * Vector Method: normalise
 *
 * Description:
 */
void Vector::normalise() {
	double m = magnitude();
	if (m > 0.0) {
		*this /= m;
	}
}

/***********************************************************************
 * Vector Method: normal
 *
 * Description:
 */
Vector Vector::normal() const {
	Vector norm = Vector(*this);
	norm.normalise();
	return norm;
}

/*******************************************************************
 * Vector Friend Method: scalar multiply
 *
 * Description:
 */
const Vector operator*(double other, const Vector &v) {
    return Vector(v)*other;
}

/***********************************************************************
 * Vector Friend Method: stream insertion operator
 *
 * Description:
 */
ostream &operator<<(ostream &output, const Vector &v) {
    output << v._x << ", " << v._y << ", " << v._z;
    return output;
}

/***********************************************************************
 * Vector Friend Method: stream extraction operator
 *
 * Description:
 */
istream &operator>>(istream  &input, Vector &v) {
    input >> v._x >> v._y >> v._z;
    return input;
}

/***********************************************************************
 * Vector Method: double * operator
 *
 * Description:
 * Return address of x coordinate
 */
Vector::operator const double * const () const {
    return &_x;
}

}

}
