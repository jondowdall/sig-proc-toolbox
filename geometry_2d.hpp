#ifndef _GEOMETRY_2D_HPP_
#define _GEOMETRY_2D_HPP_
/*
 * 2d Geometry Interface.
 */

#include <iostream>

namespace Geometry {

namespace Two_Dimensional {

/***********************************************************************
 * Class: Vector
 *
 * Description:
 *
 */
class Vector {
public:
    Vector();
    Vector(double x, double y);

    /*******************************************************************
     * Method: additive assignment operator
     *
     * Description:
     * Increment vector by other vector
     */
    Vector & operator+=(const Vector &rhs);


    /*******************************************************************
     * Method: subtractive assignment operator
     *
     * Description:
     * Decrement vector by other vector
     */
    Vector & operator-=(const Vector &rhs);


    /*******************************************************************
     * Method: multiblicative assignment operator
     *
     * Description:
     * Multiply vector by scalar.
     */
    Vector & operator*=(const double &rhs);


    /*******************************************************************
     * Method: division assignment operator
     *
     * Description:
     * Divide vector by scalar.
     */
    Vector & operator/=(const double &rhs);


    /*******************************************************************
     * Method: add operator
     *
     * Description:
     * Add 2 vectors.
     */
    const Vector operator+(const Vector &other) const;

    /*******************************************************************
     * Method: subtract operator
     *
     * Description:
     * Add 2 vectors.
     */
    const Vector operator-(const Vector &other) const;

    /*******************************************************************
     * Method: multiply operator
     *
     * Description:
     * Add 2 vectors.
     */
    const Vector operator*(const double &other) const;

    /*******************************************************************
     * Vector Friend Method: scalar multiply
     *
     * Description:
     */
    friend const Vector operator*(double other, const Vector &v);

    /*******************************************************************
     * Method: divide operator
     *
     * Description:
     * Add 2 vectors.
     */
    const Vector operator/(const double &other) const;

    /*******************************************************************
     * Method: dot
     *
     * Description:
     * Add 2 vectors.
     */
    const double dot(const Vector &other) const;

    /*******************************************************************
     * Vector Friend Method: stream insertion operator
     *
     * Description:
     */
    friend std::ostream &operator<<(std::ostream &output,
                                    const Vector &v);

    /*******************************************************************
     * Vector Friend Method: stream extraction operator
     *
     * Description:
     */
    friend std::istream &operator>>(std::istream  &input, Vector &v);

    /*******************************************************************
     * Vector Method: double * operator
     *
     * Description:
     * Return address of x coordinate
     */
    operator const double * const () const ;

protected:

private:
    double _x;
    double _y;
};

/***********************************************************************
 * Class: Point
 *
 * Description:
 *
 */
class Point {
public:

protected:

private:

};

/***********************************************************************
 * Class: Line
 *
 * Description:
 *
 */
class Line {
public:

protected:

private:

};

/***********************************************************************
 * Class: Circle
 *
 * Description:
 *
 */
class Circle {
public:

protected:

private:

};

}

}

#endif
