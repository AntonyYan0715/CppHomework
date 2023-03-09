#ifndef OPTION_H
#define OPTION_H

class Option {
public:
    // Constructor
    Option(double K, double T);
    
    // Price
    virtual double Price(double S0, double r, double v) = 0;

    // Delta
    virtual double Delta(double S0, double r, double v) = 0;
    
    // Gamma
    virtual double Gamma(double S0, double r, double v) = 0;

protected:
    double d1(double S0, double r, double v);
    double d2(double S0, double r, double v);

    // Strike
    double K_;

    // Time to maturity
    double T_;
};

#endif
