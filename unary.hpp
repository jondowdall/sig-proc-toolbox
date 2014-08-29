#ifndef _UNARY_HPP_
#define _UNARY_HPP_

/*
 * unary.hpp - interface to unary functions:
 * acos
 * asin
 * atan
 * cos
 * sin
 * tan
 * cosh
 * sinh
 * tanh
 * acosh
 * asinh
 * atanh
 * exp
 * log
 * log10
 * exp10
 * pow10
 * expm1
 * log1p
 * logb
 * exp2
 * log2
 * sqrt
 * cbrt
 * ceil
 * fabs
 * floor
 * int isinf
 * int finite
 * int isnan
 * j0
 * j1
 * y0
 * y1
 * erf
 * erfc
 * lgamma
 * tgamma
 * gamma
 * rint
 * int,ilogb
 * nearbyint
 * round
 * trunc
 * int fpclassify(double value)
 * int signbit(double value)
 * long int,lrint
 * long long int,llrint
 * long int,lround
 * long long int,llround
 */

#include "functions.hpp"

#include <string>
#include <vector>

namespace Functions {

class Unary : public Operation {
    DataSource *_input;
    Data _result;

    virtual double execute(double input) = 0;

public:
    Unary(DataSource *input);

    void set_input(DataSource *input);

    void calculate();

    Data &value();
};


class Sin : public Unary, Named {
    virtual double execute(double input);
public:
    Sin();
};

class Cos : public Unary, Named {
    virtual double execute(double input);
public:
    Cos();
};

class Tan : public Unary, Named {
    virtual double execute(double input);
public:
    Tan();
};

}

#endif

