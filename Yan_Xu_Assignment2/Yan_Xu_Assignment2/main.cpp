#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include "Currency.h"
#include "CurrencyConverter.h"

using namespace std;

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