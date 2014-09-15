#ifndef _UNARY_HPP_
#define _UNARY_HPP_

/*
 * unary.hpp - interface to unary functions:
 * acos
 * asin
 * atan
 * cos
 * sin
 * tan
 * cosh
 * sinh
 * tanh
 * acosh
 * asinh
 * atanh
 * exp
 * log
 * log10
 * exp10
 * pow10
 * expm1
 * log1p
 * logb
 * exp2
 * log2
 * sqrt
 * cbrt
 * ceil
 * fabs
 * floor
 * int isinf
 * int finite
 * int isnan
 * j0
 * j1
 * y0
 * y1
 * erf
 * erfc
 * lgamma
 * tgamma
 * gamma
 * rint
 * int,ilogb
 * nearbyint
 * round
 * trunc
 * int fpclassify(double value)
 * int signbit(double value)
 * long int,lrint
 * long long int,llrint
 * long int,lround
 * long long int,llround
 */

#include "functions.hpp"

#include <cmath>

#include <string>
#include <vector>

namespace Functions {

typedef double UnaryDoubleFunction(double input);

template <UnaryDoubleFunction function>
class Unary : public Operation {
public:
    Unary() {}
    Unary(DataSource *input) : _input(input) {}

    void set_input(DataSource *input);

    double operator() (DataSource *input) {
        return execute(input->as_real());
    }

    /***************************************************************************
     * method: class_name
     *
     * Description:
     * Return a string containing the name of this class.
     */
     std::string class_name() {return _name;}

    /***************************************************************************
     * method: static_class_name
     *
     * Description:
     * Return a string containing the name of this class.
     */
     static std::string static_class_name() {return _name;}

private:
    DataSource *_input;
    Data _result;

    double execute(double input) {
        return function(input);
    }

    static const std::string _name;
};

typedef Unary<acos> Arc_Cosine;
typedef Unary<asin> Arc_Sinine;
typedef Unary<atan> Arc_Tangent;
typedef Unary<cos> Cosine;
typedef Unary<sin> Sine;
typedef Unary<tan> Tangent;
typedef Unary<cosh> Hyperbolic_Cosine;
typedef Unary<sinh> Hyperbolic_Sine;
typedef Unary<tanh> Hyperbolic_Tangent;
typedef Unary<acosh> Inverse_Hyperbolic_Cosine;
typedef Unary<asinh> Inverse_Hyperbolic_Sine;
typedef Unary<atanh> Inverse_Hyperbolic_Tangent;
typedef Unary<exp> Exponetial;
typedef Unary<log> Logarithm;
typedef Unary<log10> Logarithm_Base10;
typedef Unary<exp10> Exponetial_Base10;
typedef Unary<pow10> Power_Base10;
typedef Unary<expm1> Exponetial_Minus_1;
typedef Unary<log1p> Logarithm_Plus_1;
typedef Unary<logb> Exponent;
typedef Unary<exp2> Exponetial_Base2;
typedef Unary<log2> Logarithm_Base2;
typedef Unary<sqrt> Square_Root;
typedef Unary<cbrt> Cube_Root;
typedef Unary<ceil> Ceiling;
typedef Unary<fabs> Absolute;
typedef Unary<floor> Floor;
typedef Unary<j0> Bessel1_Order0;
typedef Unary<j1> Bessel1_Order1;
typedef Unary<y0> Bessel2_Order0;
typedef Unary<y1> Bessel2_Order1;
typedef Unary<erf> Error_Function;
typedef Unary<erfc> Complementary_Error_Function;
typedef Unary<lgamma> Log_Gamma;
typedef Unary<tgamma> Gamma;
typedef Unary<gamma> Old_Gamma;
typedef Unary<rint> Nearest_Int_Check;
typedef Unary<nearbyint> Nearest_Int;
typedef Unary<round> Round;
typedef Unary<trunc> Truncate;

}


#endif

