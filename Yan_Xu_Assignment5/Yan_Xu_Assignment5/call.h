#ifndef CALL_H
#define CALL_H
#include "option.h"

class EuropeanCall : public Option {
public:
    // Constructor
    EuropeanCall(double K, double T);

    // Get Payoff
    double GetExpirationPayoff(double S_T) const override;
};

#endif