#include "Currency.h"

Currency::Currency(string symbol, double rate)
	: symbol_(symbol),
	exchange_rate_(rate) {
}

double Currency::GetExchangeRate() {
	return exchange_rate_;
}

void Currency::SetExchangeRate(double rate) {
	exchange_rate_ = rate;
}

string Currency::GetSymbol() {
	return symbol_;
}

void Currency::SetSymbol(string symbol) {
	symbol_ = symbol;
}

double Currency::ConvertFromUSD(double value) {
	return value * exchange_rate_;
}

double Currency::ConvertToUSD(double value) {
	return value / exchange_rate_;
}