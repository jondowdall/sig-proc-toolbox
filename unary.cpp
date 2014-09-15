/*
 * unary.cpp - implementation of unary functions.
 */

#include "unary.hpp"

#include <cmath>

using namespace std;

namespace Functions {


template<> const string Unary<acos>::_name("Arc Cosine");
template<> const string Unary<asin>::_name("Arc Sinine");
template<> const string Unary<atan>::_name("Arc Tangent");
template<> const string Unary<cos>::_name("Cosine");
template<> const string Unary<sin>::_name("Sine");
template<> const string Unary<tan>::_name("Tangent");
template<> const string Unary<cosh>::_name("Hyperbolic Cosine");
template<> const string Unary<sinh>::_name("Hyperbolic Sine");
template<> const string Unary<tanh>::_name("Hyperbolic Tangent");
template<> const string Unary<acosh>::_name("Inverse Hyperbolic Cosine");
template<> const string Unary<asinh>::_name("Inverse Hyperbolic Sine");
template<> const string Unary<atanh>::_name("Inverse Hyperbolic Tangent");
template<> const string Unary<exp>::_name("Exponetial");
template<> const string Unary<log>::_name("Logarithm");
template<> const string Unary<log10>::_name("Logarithm Base10");
template<> const string Unary<exp10>::_name("Exponetial Base10");
template<> const string Unary<pow10>::_name("Power Base10");
template<> const string Unary<expm1>::_name("Exponetial Minus 1");
template<> const string Unary<log1p>::_name("Logarithm Plus 1");
template<> const string Unary<logb>::_name("Exponent");
template<> const string Unary<exp2>::_name("Exponetial Base2");
template<> const string Unary<log2>::_name("Logarithm Base2");
template<> const string Unary<sqrt>::_name("Square Root");
template<> const string Unary<cbrt>::_name("Cube Root");
template<> const string Unary<ceil>::_name("Ceiling");
template<> const string Unary<fabs>::_name("Absolute");
template<> const string Unary<floor>::_name("Floor");
template<> const string Unary<j0>::_name("Bessel1 Order0");
template<> const string Unary<j1>::_name("Bessel1 Order1");
template<> const string Unary<y0>::_name("Bessel2 Order0");
template<> const string Unary<y1>::_name("Bessel2 Order1");
template<> const string Unary<erf>::_name("Error Function");
template<> const string Unary<erfc>::_name("Complementary Error Function");
template<> const string Unary<lgamma>::_name("Log Gamma");
template<> const string Unary<tgamma>::_name("Gamma");
template<> const string Unary<gamma>::_name("Old Gamma");
template<> const string Unary<rint>::_name("Nearest Int Check");
template<> const string Unary<nearbyint>::_name("Nearest Int");
template<> const string Unary<round>::_name("Round");
template<> const string Unary<trunc>::_name("Truncate");


#if 0

template <Func function, string name>
Unary<function, name>::Unary(DataSource *input=&null_source)
  : _input(input),
    _result(1, 0.0) {
}

template <Func function, string name>
void Unary<function, name>::set_input(DataSource *input) {
    _input = input;
}


template <>
void Unary::calculate() {
    Data input = _input->value();
    _result.resize(input.size(), 0.0);
    for(unsigned int i = 0; i < input.size(); ++i) {
        _result[i] = execute(input[i]);
    }
}

template <Func function, string name>
Data &Unary<function, name>::value() {
    if (recalculate_required()) {
        calculate();
    }
    return _result;
}

#endif

}
