#include <iostream>
#include "call.h"
#include "put.h"

using namespace std;

int main() {
    // Parameters for call
    double S0_1 = 100;
    double K_1 = 100;
    double T_1 = 1;
    double v_1 = 0.3;
    double r_1 = 0.05;

    // Parameters for put
    double S0_2 = 120;
    double K_2 = 120;
    double T_2 = 2;
    double v_2 = 0.4;
    double r_2 = 0.1;

    EuropeanCall call_1(K_1, T_1);
    cout << "Call price: " << call_1.Price(S0_1, r_1, v_1)
         << "\nDelta: " << call_1.Delta(S0_1, r_1, v_1)
         << "\nGamma: " << call_1.Gamma(S0_1, r_1, v_1) << endl;

    EuropeanPut put_1(K_2, T_2);
    cout << "\nPut price: " << put_1.Price(S0_2, r_2, v_2)
         << "\nDelta: " << put_1.Delta(S0_2, r_2, v_2)
         << "\nGamma: " << put_1.Gamma(S0_2, r_2, v_2) << endl;
}
