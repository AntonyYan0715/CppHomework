#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include "Currency.h"
#include "CurrencyConverter.h"

using namespace std;

double ConvertFromUSD(double value, CurrencyType foreignCurrency) {
	double amount;

	switch (foreignCurrency) {
	case CNY: {
		Currency cny("CNY", 6.70);
		amount = cny.ConvertFromUSD(value);
		break;
	}
	case EUR: {
		Currency eur("EUR", 0.92);
		amount = eur.ConvertFromUSD(value);
		break;
	}
	case GBP: {
		Currency gbp("GBP", 0.82);
		amount = gbp.ConvertFromUSD(value);
		break;
	}
	case CAD: {
		Currency cad("CAD", 1.34);
		amount = cad.ConvertFromUSD(value);
		break;
	}
	case AUD: {
		Currency aud("AUD", 1.43);
		amount = aud.ConvertFromUSD(value);
		break;
	}
	case JPY: {
		Currency jpy("JPY", 127.90);
		amount = jpy.ConvertFromUSD(value);
		break;
	}
	default: {
		Currency usd("USD", 1.00);
		amount = usd.ConvertFromUSD(value);
	}
	}
	return amount;
}

double ConvertToUSD(double value, CurrencyType foreignCurrency) {
	double amount;

	switch (foreignCurrency) {
	case CNY: {
		Currency cny("CNY", 6.70);
		amount = cny.ConvertToUSD(value);
		break;
	}
	case EUR: {
		Currency eur("EUR", 0.92);
		amount = eur.ConvertToUSD(value);
		break;
	}
	case GBP: {
		Currency gbp("GBP", 0.82);
		amount = gbp.ConvertToUSD(value);
		break;
	}
	case CAD: {
		Currency cad("CAD", 1.34);
		amount = cad.ConvertToUSD(value);
		break;
	}
	case AUD: {
		Currency aud("AUD", 1.43);
		amount = aud.ConvertToUSD(value);
		break;
	}
	case JPY: {
		Currency jpy("JPY", 127.90);
		amount = jpy.ConvertToUSD(value);
		break;
	}
	default: {
		Currency usd("USD", 1.00);
		amount = usd.ConvertToUSD(value);
	}
	}
	return amount;
}
