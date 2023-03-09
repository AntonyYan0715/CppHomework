#include "call.h"

EuropeanCall::EuropeanCall(double K, double T)
	: Option(K, T) {
}

double EuropeanCall::GetExpirationPayoff(double S_T) const {
	double payoff = S_T - K_;

	if (payoff > 0) {
		return payoff;
	}
	else {
		return 0;
	}
}