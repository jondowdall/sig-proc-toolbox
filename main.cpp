/*
 * main.cpp - entry point
 */

#include <iostream>

#include <fenv.h>

#include "functions.hpp"
#include "geometry_2d.hpp"
#include "geometry_3d.hpp"

using namespace std;

int main(int argc, char *argv[]) {

    cout << "Hello World!" << endl;
    cout << fegetround() << endl;
 
    Geometry::Three_Dimensional::Vector v1;
    Geometry::Three_Dimensional::Vector v2(1.0, 2.0, 1.5);
    Geometry::Three_Dimensional::Vector v3(3.0, 2.0, 1.0);

    cout << "v1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;
    cout << "v3 = " << v3 << endl;

    cout << "v1 + v2 = " << v1 + v2 << endl;
    cout << "v1 - v2 = " << v1 - v2 << endl;

    cout << "v2 * 2 = " << v2 * 2.0 << endl;
    cout << "v2 / 2 = " << v2 / 2 << endl;

    cout << "v1.dot(v2) = " << v1.dot(v2) << endl;
    cout << "2 * v2 = " << 2.0 * v2 << endl;
    cout << "v2 x v3 = " << v2.cross(v3) << endl;

    double d = v2.magnitude();
    d += 1.0;

    cout << "v2.normal() = " << v2.normal() << endl;
    v3.normalise();
    cout << "Normalised v3 = " << v3 << endl;

    return 0;
}
