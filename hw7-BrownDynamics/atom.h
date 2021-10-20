#ifndef ATOM_H
#define ATOM_H
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdio>
#include "vec.h"
#define PI 3.1415926

using namespace std;

// Return a uniform random number in [a,b)
double unirand(double a, double b) {
    return a + (b-a) * (rand() / (float)RAND_MAX);
}

// Return a random vector with norm L
Vec randvec(double L) {
    Vec v(2);
    double theta = unirand(0, 2*PI);
    v.init(vector<double>{L*cos(theta), L*sin(theta)});
    return v;
}

class Atom {
public:
    double mass;
    Vec position;  // r(t)
    Vec velocity;  // v(t - dt/2)
    Atom(double m, Vec r, Vec v): mass(m), position(r), velocity(v) {}
};

class Motion {
public:
    Atom atom;
    double kT;    // temperature kT of the system
    double gamma; // coefficient of viscosity
    double dt;    // time interval Δt
    double factor = atom.mass * (1 + 0.5*gamma*dt);

    Motion(Atom a, double T, double g, double t): atom(a), kT(T), gamma(g), dt(t) {}
    void run();
    void output(FILE *fp, int istep);
};

void Motion::run() {
    double L = sqrt((2 * atom.mass * gamma * kT) / dt);
    Vec a = randvec(L) - atom.velocity * atom.mass * gamma; // acceleration of atom
    atom.velocity = atom.velocity + (a/factor) * dt;        // update the velocity of atom
    atom.position = atom.position + atom.velocity * dt;     // update the position of atom
}

void Motion::output(FILE *fp, int istep) {
    fprintf(fp, "%5d %10f %10f %10f %10f\n", istep, atom.position.data[0],\
    atom.position.data[1], atom.velocity.data[0], atom.velocity.data[1]);
}

#endif