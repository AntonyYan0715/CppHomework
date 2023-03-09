#include "Option.h"

//Constructor
Option::Option(double K, double T)
    :K_(K), T_(T) {
}

double Option::GetTimeToExpiration() const {
    return T_;
}