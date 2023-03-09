#include "put.h"
#include "normal.h"
#include <cmath>

//Constructor
EuropeanPut::EuropeanPut(double K, double T)
    : Option(K, T) {
}

double EuropeanPut::Price(double S0, double r, double v) {
    double call_price;
    double d_1 = d1(S0, r, v);
    double d_2 = d2(S0, r, v);
    call_price = (K_ * exp(-r * T_) * cdf(-d_2)) - (S0 * cdf(-d_1));
    return call_price;
}

double EuropeanPut::Delta(double S0, double r, double v) {
    double delta;
    double d_1 = d1(S0, r, v);
    delta = cdf(d_1) - 1;
    return delta;
}

double EuropeanPut::Gamma(double S0, double r, double v) {
    double gamma;
    double d_1 = d1(S0, r, v);
    gamma = pdf(d_1) / (S0 * v * sqrt(T_));
    return gamma;
}