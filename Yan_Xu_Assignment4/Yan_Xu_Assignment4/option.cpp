#include <cmath>
#include "Option.h"

//Constructor
Option::Option(double K, double T)
    :K_(K), T_(T) {
}

double Option::d1(double S0, double r, double v) {
    double d1 = log(S0 * exp(r * T_) / K_) / (v * sqrt(T_)) + (v * sqrt(T_) / 2);
    return d1;
}

double Option::d2(double S0, double r, double v) {
    double d2 = log(S0 * exp(r * T_) / K_) / (v * sqrt(T_)) - (v * sqrt(T_) / 2);
    return d2;
}