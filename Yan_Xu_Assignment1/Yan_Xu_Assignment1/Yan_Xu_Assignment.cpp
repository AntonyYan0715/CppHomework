#include <iostream>
#include <cmath>

using namespace std;

enum CurrencyType {USD=0, CNY=1, EUR=2, GBP=3, CAD=4, AUD=5, JPY=6};

double ConvertFromUSD(double amount, CurrencyType foreignCurrency) {
	double rate;

	switch (foreignCurrency) {
	case CNY:
		rate = 6.70;
		break;
	case EUR:
		rate = 0.92;
		break;
	case GBP:
		rate = 0.82;
		break;
	case CAD:
		rate = 1.34;
		break;
	case AUD:
		rate = 1.43;
		break;
	case JPY:
		rate = 127.90;
		break;
	default:
		rate = 1.0;
	}
	return amount * rate;
}

double ConvertToUSD(double amount, CurrencyType foreignCurrency) {
	double rate;

	switch (foreignCurrency) {
	case CNY:
		rate = 6.70;
		break;
	case EUR:
		rate = 0.92;
		break;
	case GBP:
		rate = 0.82;
		break;
	case CAD:
		rate = 1.34;
		break;
	case AUD:
		rate = 1.43;
		break;
	case JPY:
		rate = 127.90;
		break;
	default:
		rate = 1.0;
	}
	return amount / rate;
}

int main() {
	double amount;
	int base, foreign;
	cout << "Enter amount. Enter 0 to exit: ";
	cin >> amount;

	while (amount != 0) {
		cout << "\nEnter base currency (USD=0 / CNY=1 / EUR=2 / GBP=3 / CAD=4 / AUD=5 / JPY=6): ";
		cin >> base;
		cout << "\nEnter foreign currency (USD=0 / CNY=1 / EUR=2 / GBP=3 / CAD=4 / AUD=5 / JPY=6): ";
		cin >> foreign;
		double baseToUSD = ConvertToUSD(amount, static_cast<CurrencyType>(base));
		double USDToForeign = ConvertFromUSD(baseToUSD, static_cast<CurrencyType>(foreign));
		cout << "\nAmount in foreign currency is: " << round(USDToForeign * 100.0) / 100.0;
		cout << "\n\nEnter amount. Enter 0 to exit: ";
		cin >> amount;
	}
}