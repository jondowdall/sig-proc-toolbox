/*
 * functions.hpp - interface to the maths functions.
 */

#include <string>
#include <vector>

namespace Functions {

typedef std::vector<double> Data;

class DataSource {
public:
    virtual Data & value() = 0;
};

class NullDataSource : public DataSource {
    Data _value;
public:
    NullDataSource();
    virtual Data & value();
};

class Operation : public DataSource {
public:
    virtual void calculate() = 0;
    virtual bool recalculate_required() {return true;}
};

class Named {
    std::string _name;
public:
    Named(std::string name);
    std::string name();
};

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


class Reduce : public Operation {
    DataSource *_input;
    Data _result;
public:
    Reduce(DataSource *input);

    void calculate();

    Data &value();
};

}
