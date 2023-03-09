#ifndef CURRENCYFACTORY_H
#define CURRENCYFACTORY_H

#include <map>
#include <fstream>
#include <sstream>
#include <iostream>
#include <optional>
#include <exception>
#include "Currency.h"

using namespace std;

// Change #3: Create CurrencyFactory
class CurrencyFactory {
public:
    CurrencyFactory(string fileName);
    ~CurrencyFactory();

    optional <Currency*> GetCurrency(string currencyType);

private:
    map <string, Currency*> currencies_map_;
};

#endif