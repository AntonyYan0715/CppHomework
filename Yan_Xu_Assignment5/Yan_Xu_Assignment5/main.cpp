#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Call.h"
#include "Put.h"
#include "MCPricer.h"

using namespace std;

int main() {
	srand(time(NULL));

	double S0 = 100.0;
	double sigma = 0.3;
	double r = 0.01;
	double T = 2.0;
	double K = 100.0;
	double Path1 = 1e04;
	double Path2 = 1e05;
	double Path3 = 1e06;

	MCPricer mc;
	EuropeanCall call(K, T);
	EuropeanPut put(K, T);

	double callPrice1 = mc.Price(call, S0, sigma, r, Path1);
	cout << "Call Price: " << callPrice1 << endl;
	double callPrice2 = mc.Price(call, S0, sigma, r, Path2);
	cout << "Call Price: " << callPrice2 << endl;
	double callPrice3 = mc.Price(call, S0, sigma, r, Path3);
	cout << "Call Price: " << callPrice3 << endl;

	double putPrice1 = mc.Price(put, S0, sigma, r, Path1);
	cout << "Put Price: " << putPrice1 << endl;
	double putPrice2 = mc.Price(put, S0, sigma, r, Path2);
	cout << "Put Price: " << putPrice2 << endl;
	double putPrice3 = mc.Price(put, S0, sigma, r, Path3);
	cout << "Put Price: " << putPrice3 << endl;
}