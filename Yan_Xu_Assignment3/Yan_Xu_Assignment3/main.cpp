#include "Currency.h"
#include "CurrencyFactory.h"

// Used Change #3 #4 #5 #6 #7 #8 #10 #11
int main() {
	string filename = "D:\\Code\\CurrencyRates.txt";
	CurrencyFactory factory(filename);

	double amount;
	string base, foreign;
	cout << "Enter amount. Enter 0 to exit: ";
	cin >> amount;

	while (amount != 0) {
		cout << "\nEnter base currency (USD/ EUR/ GBP/ CAD/ AUD): ";
		cin >> base;
		optional <Currency*> baseCurrency = factory.GetCurrency(base);
		cout << "\nEnter foreign currency (USD/ EUR/ GBP/ CAD/ AUD): ";
		cin >> foreign;
		optional <Currency*> foreignCurrency = factory.GetCurrency(foreign);

		double baseToUSD = (*baseCurrency) -> ConvertToUSD(amount);
		double USDToForeign = (*foreignCurrency) -> ConvertFromUSD(baseToUSD);

		cout << "\nAmount in foreign currency is: " << round(USDToForeign * 100.0) / 100.0;
		cout << "\n\nEnter amount. Enter 0 to exit: ";
		cin >> amount;
	}
}