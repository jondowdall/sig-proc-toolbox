/*
 * functions.hpp - interface to the maths functions.
 */
#ifndef _FUNCTIONS_HPP_
#define _FUNCTIONS_HPP_

#include <string>
#include <vector>

namespace Functions {

typedef std::vector<double> Data;

class DataSource {
public:
//    virtual Data & value() = 0;
      double as_real() {return 0.0;}
};

class NullDataSource : public DataSource {
    Data _value;
public:
    NullDataSource();
    virtual Data & value();
};

extern NullDataSource null_source;

class Operation : public DataSource {
public:
//    virtual void calculate() = 0;
//    virtual bool recalculate_required() {return true;}
    virtual std::string class_name() {return "Operation<Abstract>";}
};

class Named {
    std::string _name;
public:
    Named(std::string name);
    std::string name();
};

class Join : public Operation {
    DataSource *_input;
    Data _result;
public:
    Join(DataSource *input);

    void calculate();

    Data &value();
};

}

#endif
