#ifndef OPTION_H
#define OPTION_H

class Option {
public:
    // Constructor
    Option(double K, double T);

    double GetTimeToExpiration() const;
    virtual double GetExpirationPayoff(double S_T) const = 0;

protected:
    // Strike
    double K_;

    // Time to maturity
    double T_;
};

#endif
