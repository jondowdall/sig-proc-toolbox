/*
 * binary.cpp - implementation of binary functions.
 */

#include "binary.hpp"

#include <cmath>

using namespace std;

namespace Functions {

Binary::Binary(DataSource *input1=&null_source,
               DataSource *input2=&null_source)
  : _input1(input1),
    _input2(input2) {
}

void Binary::set_input1(DataSource *input) {
    _input1 = input;
}

void Binary::set_input2(DataSource *input) {
    _input2 = input;
}

void Binary::calculate() {
    Data input1 = _input1->value();
    Data input2 = _input2->value();
    unsigned int length = input1.size() < input2.size() ? input1.size() : input2.size();
    _result.resize(length, 0.0);
    for(unsigned int i = 0; i < length; ++i) {
        _result[i] = execute(input1[i], input2[i]);
    }
}

Data &Binary::value() {
    if (recalculate_required()) {
        calculate();
    }
    return _result;
}

Add::Add()
  : Named("+") {
}

double Add::execute(double input1, double input2) {
    return input1 + input2;
}

Subtract::Subtract()
  : Named("-") {
}

double Subtract::execute(double input1, double input2) {
    return input1 - input2;
}

Multiply::Multiply()
  : Named("*") {
}

double Multiply::execute(double input1, double input2) {
    return input1 * input2;
}

Divide::Divide()
  : Named("/") {
}

double Divide::execute(double input1, double input2) {
    return input1 / input2;
}

}
