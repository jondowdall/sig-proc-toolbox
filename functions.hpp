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

extern NullDataSource null_source;

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

class Reduce : public Operation {
    DataSource *_input;
    Data _result;
public:
    Reduce(DataSource *input);

    void calculate();

    Data &value();
};

}
