#include "put.h"

EuropeanPut::EuropeanPut(double K, double T)
	: Option(K, T) {
}

double EuropeanPut::GetExpirationPayoff(double S_T) const {
	double payoff = K_ - S_T;

	if (payoff > 0) {
		return payoff;
	}
	else {
		return 0;
	}
}