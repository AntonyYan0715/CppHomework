#include <vector>
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdio>
#include "vec.h"
#include "atom.h"
#include "use.h"

using namespace std;

int main(int argc, char *argv[]) {
    // seed random generator
    srand(time(NULL));

    // parameters
    int nstep = 10000;
    double mass = 1.0;
    double kT = 1.0;
    double gamma = 0.1;
    double dt = 0.1;
    const char *filename = "output.dat";

    getArgs(argc, argv, &nstep, &mass, &kT, &gamma, &dt);
    Vec v(2);
    v.init(vector<double>{0,0});
    Atom a = Atom(mass, v, v);
    Motion mo = Motion(a, kT, gamma, dt);
    FILE *fp = fopen(filename, "w");

    for (int i=0; i<nstep; ++i) {
        mo.output(fp, i);
        mo.run();
    }
    fclose(fp);
    return 0;
}
