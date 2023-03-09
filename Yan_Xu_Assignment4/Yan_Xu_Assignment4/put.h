#ifndef PUT_H
#define PUT_H
#include "option.h"

class EuropeanPut : public Option {
public:
    // Constructor
    EuropeanPut(double K, double T);
    
    // Price
    double Price(double S0, double r, double v) override;
    
    // Delta
    double Delta(double S0, double r, double v) override;
    
    // Gamma
    double Gamma(double S0, double r, double v) override;

};

#endif
