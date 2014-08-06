#ifndef _BINARY_HPP_
#define _BINARY_HPP_

/*
 * binary.hpp - interface to the maths functions.
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
