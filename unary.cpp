/*
 * unary.cpp - implementation of unary functions.
 */

#include "unary.hpp"

#include <cmath>

using namespace std;

namespace Functions {

Unary::Unary(DataSource *input=&null_source)
  : _input(input),
    _result(1, 0.0) {
}

void Unary::set_input(DataSource *input) {
    _input = input;
}

void Unary::calculate() {
    Data input = _input->value();
    _result.resize(input.size(), 0.0);
    for(unsigned int i = 0; i < input.size(); ++i) {
        _result[i] = execute(input[i]);
    }
}

Data &Unary::value() {
    if (recalculate_required()) {
        calculate();
    }
    return _result;
}

Sin::Sin()
  : Named("Sin") {
}

double Sin::execute(double input) {
    return sin(input);
}

Cos::Cos()
  : Named("Cos") {
}

double Cos::execute(double input) {
    return cos(input);
}

Tan::Tan()
  : Named("Tan") {
}

double Tan::execute(double input) {
    return tan(input);
}

}
