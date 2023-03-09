#ifndef CALL_H
#define CALL_H
#include "option.h"

class EuropeanCall : public Option {
public:
    // Constructor
    EuropeanCall(double K, double T);

    // Price
    double Price(double S0, double r, double v) override;

    // Delta
    double Delta(double S0, double r, double v) override;

    // Gamma
    double Gamma(double S0, double r, double v) override;

};

#endif
