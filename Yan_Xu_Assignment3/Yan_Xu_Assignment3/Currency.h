#ifndef CURRENCY_H
#define CURRENCY_H

#include <iostream>

using namespace std;

class Currency {
public:
	// Change #11: Using Default Implementations
	Currency() = default;
	Currency(string symbol, double rate);
	~Currency() = default;
	Currency(const Currency& other) = default;
	Currency& operator=(const Currency& other) = default;

	double GetExchangeRate();
	void SetExchangeRate(double rate);
	string GetSymbol();
	void SetSymbol(string symbol);

	double ConvertFromUSD(double value);
	double ConvertToUSD(double value);

private:
	double exchange_rate_;
	string symbol_;
};


#endif