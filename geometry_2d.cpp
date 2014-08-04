/*
 * 2d Geometry Implementation.
 */

#include "geometry_2d.hpp"

using namespace std;

namespace Geometry {

namespace Two_Dimensional {

/***********************************************************************
 * Vector constructor
 *
 * Description:
 */
Vector::Vector()
  : _x(0.0),
    _y(0.0) {
}

/***********************************************************************
 * Vector constructor
 *
 * Description:
 */
Vector::Vector(double x, double y)
  : _x(x),
    _y(y) {
}

/***********************************************************************
 * Vector Method: Vector additive assignment operator
 *
 * Description:
 */
Vector & Vector::operator+=(const Vector &rhs) {
    _x += rhs._x;
    _y += rhs._y;
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
 * Vector Method: dot product
 *
 * Description:
 */
const double Vector::dot(const Vector &other) const {
    return _x * other._x + _y * other._y;
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
    output << v._x << ", " << v._y;
    return output;
}

/***********************************************************************
 * Vector Friend Method: stream extraction operator
 *
 * Description:
 */
istream &operator>>(istream  &input, Vector &v) {
    input >> v._x >> v._y;
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
