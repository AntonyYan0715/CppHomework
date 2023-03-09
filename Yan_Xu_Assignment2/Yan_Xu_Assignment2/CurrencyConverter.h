#ifndef CURRENCYCONVERTER_H
#define CURRENCYCONVERTER_H
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

enum CurrencyType { USD = 0, CNY = 1, EUR = 2, GBP = 3, CAD = 4, AUD = 5, JPY = 6 };

double ConvertFromUSD(double value, CurrencyType foreignCurrency);
double ConvertToUSD(double value, CurrencyType foreignCurrency);

#endif