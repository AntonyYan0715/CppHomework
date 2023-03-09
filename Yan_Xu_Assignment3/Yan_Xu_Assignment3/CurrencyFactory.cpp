#include "CurrencyFactory.h"

// Change #8: Using std::optional
optional <Currency*> CurrencyFactory::GetCurrency(string currencyType) {
    auto iter = currencies_map_.find(currencyType);
    if (iter == currencies_map_.end()) {
        return nullopt;
    }
    return iter -> second;
}

// Change #5: Delete to avoid memory leak
CurrencyFactory::~CurrencyFactory() {
    for (auto iter = currencies_map_.begin(); iter != currencies_map_.end(); ++iter) {
        delete iter->second;
    }
}

// Change #4: Free-store
// Change #6: Using a map
// Change #7: Using Exceptions
// Change #10: Using Streams
CurrencyFactory::CurrencyFactory(string fileName) {
    ifstream infile(fileName);
    if (!infile) {
        throw exception("Unable to open file.");
    }

    string data;
    string symbol;
    double rate;

    while (infile) {
        getline(infile, data);
        istringstream iss(data);
        iss >> symbol >> rate;

        currencies_map_[symbol] = new Currency(symbol, rate);
    }
}