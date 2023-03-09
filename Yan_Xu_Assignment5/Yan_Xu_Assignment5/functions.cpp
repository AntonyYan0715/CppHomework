#include "functions.h"

const double PI = atan(1.0) * 4;

double BoxMuller(double x, double y) {
	return sqrt(-2.0 * log(x)) * cos(2 * PI * y);
}
