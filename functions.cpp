/*
 * functions.cpp - implementation of the functions.
 */

#include "functions.hpp"

#include <cmath>

using namespace std;

namespace Functions {

NullDataSource::NullDataSource()
  : _value(1, 0.0) {
}

vector<double> & NullDataSource::value() {
    return _value;
}

NullDataSource null_source;

Named::Named(string name)
  : _name(name) {
}

string Named::name() {
    return _name;
}

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
