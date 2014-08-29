#ifndef _BINARY_HPP_
#define _BINARY_HPP_

/*
 * binary.hpp - interface to the binary functions:
 * add
 * subtract
 * multiply
 * divide
 * 
 * atan2 (double y, double x);
 * frexp (double x, int *__exponent);
 * ldexp (double x, int __exponent);
 * modf (double x, _Mdouble_ *__iptr);
 * pow (double x, double y);
 * hypot (double x, double y);
 * fmod (double x, double y);
 * copysign (double x, double y);
 * jn (int, double x);
 * yn (int, double x);
 * nextafter (double x, double y);
 * nexttoward (double x, long double y);
 * remainder (double x, double y);
 * scalbn (double x, int n);
 * scalbln (double x, long int n);
 * remquo (double x, double y, int *__quo);
 * fdim (double x, double y);
 * fmax (double x, double y);
 * fmin (double x, double y);
 * fma (double x, double y, double z);
 * 
 */
#include "functions.hpp"

#include <string>
#include <vector>

namespace Functions {

class Binary : public Operation {
    DataSource *_input1;
    DataSource *_input2;
    Data _result;
    virtual double execute(double input1, double input2) = 0;

public:
    Binary(DataSource *input1, DataSource *input2);

    void set_input1(DataSource *input);
    void set_input2(DataSource *input);

    void calculate();

    Data &value();
};


class Add : public Binary, Named {
    virtual double execute(double input1, double input2);
public:
    Add();
};

class Subtract : public Binary, Named {
    virtual double execute(double input1, double input2);
public:
    Subtract();
};

class Multiply : public Binary, Named {
    virtual double execute(double input1, double input2);
public:
    Multiply();
};

class Divide : public Binary, Named {
    virtual double execute(double input1, double input2);
public:
    Divide();
};

}

#endif
