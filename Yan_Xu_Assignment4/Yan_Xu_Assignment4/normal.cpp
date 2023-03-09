#include <cmath>
#include "normal.h"

const double PI = atan(1.0) * 4;

// Normal Distribution Functions
double cdf(double x) {
    return 0.5 * (1 + erf(x / sqrt(2)));
}

double pdf(double x) {
    return exp(-0.5 * pow(x, 2)) / (sqrt(2 * PI));
}