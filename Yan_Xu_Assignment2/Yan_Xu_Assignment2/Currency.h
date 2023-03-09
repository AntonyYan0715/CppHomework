#ifndef CURRENCY_H
#define CURRENCY_H
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

class Currency {
public:
	Currency();
	Currency(string symbol, double rate);
	~Currency();

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