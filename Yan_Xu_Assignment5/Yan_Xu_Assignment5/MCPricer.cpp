#include <cmath>
#include "MCPricer.h"
#include "functions.h"

double MCPricer::Price(const Option& option, double stockPrice, double vol, double rate, unsigned long paths) {
	double T = option.GetTimeToExpiration();
	double TotalPayoff = 0.0;
	unsigned long ValidPaths = 0;

	while (ValidPaths < paths) {
		double x = static_cast<double>(rand()) / RAND_MAX;
		if (x == 0) continue;

		double y = static_cast<double>(rand()) / RAND_MAX;
		double z = BoxMuller(x, y);
		double S_T = stockPrice * exp((rate - vol * vol / 2.0) * T + vol * z * sqrt(T));
		double payoff = option.GetExpirationPayoff(S_T);
		TotalPayoff += payoff;
		ValidPaths += 1;
	}
	return (exp(-rate * T) / ValidPaths) * TotalPayoff;
}