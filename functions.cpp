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

}
