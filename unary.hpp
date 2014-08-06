#ifndef _UNARY_HPP_
#define _UNARY_HPP_

/*
 * unary.hpp - interface to unary functions.
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

