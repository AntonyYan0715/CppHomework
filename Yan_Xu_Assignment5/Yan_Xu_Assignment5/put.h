#ifndef PUT_H
#define PUT_H
#include "option.h"

class EuropeanPut : public Option {
public:
    // Constructor
    EuropeanPut(double K, double T);

    // Get Payoff
    double GetExpirationPayoff(double S_T) const override;
};

#endif