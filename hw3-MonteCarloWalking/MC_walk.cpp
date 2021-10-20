#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <unistd.h>
#define PI 3.1415926

using namespace std;

// Return a uniform random number in [a,b)
double unirand(double a, double b){
    return a + (b-a) * (rand() / (float)RAND_MAX);
}

class MC_walker {
    public:
    double x;  // x-position
    double y;  // y-position
    double s;  // stepsize
    double kT; // temperature

    MC_walker(double X, double Y, double S, double T) {
        x = X;
        y = Y;
        s = S;
        kT = T;
    }

    double energy(double x, double y);
    void walk();
    int state();
    void output(FILE *fp, int istep);
};

// Calculate energy of the particle
double MC_walker::energy(double x, double y) {
    double d = sqrt(x*x + y*y);
    if (d <= 2)
    return -0.5 * cos(0.5 * PI * d) - cos(1.5 * PI * d);
    else
    return INFINITY;
}

// One step of the Monte Carlo random walk
void MC_walker::walk() {
    double angle = unirand(0, 2 * PI);
    double x1 = x + s * cos(angle);
    double y1 = y + s * sin(angle);
    double deltaE = energy(x1, y1) - energy(x, y);
    double prob = exp(-deltaE / kT);

    if (deltaE < 0) {
        x = x1;
        y = y1;
    }
    else if (unirand(0, 1) < prob) {
        x = x1;
        y = y1;
    }
}

// Return the state of the particle
int MC_walker::state() {
    double d = sqrt(x*x + y*y);
    if (d < 0.698)
    return 0;     // Ground State
    else if (d < 2)
    return 1;     // Excited State
    else
    return 2;
}

// Output data to the file
void MC_walker::output(FILE *fp, int istep) {
    if (state() == 0)
    fprintf(fp, "%10d   Ground state: %10.5f %10.5f\n", istep, x, y);
    else
    fprintf(fp, "%10d   Excited state: %10.5f %10.5f\n", istep, x, y);
}

// the usage
void usage(char *program) {
    fprintf(stderr, "\nProgram Usage:\n%s\n", program);
    fprintf(stderr,
            "     [ -n  10000 ]  number of steps per run, default 10000\n");
    fprintf(stderr,
            "     [ -s  0.1 ]    size of each step, default 0.1\n");
    fprintf(stderr,
            "     [ -T  1.0 ]    temperature kT of the system, default 1.0\n");
    fprintf(stderr, "     [ -h ]         display this information\n");
    fprintf(stderr, "\n");
    exit(1);
}

// Get system arguments from command line
void getArgs(int argc, char **argv, int *nstep, double *s, double *kT) {
    char ch;
    while ((ch = getopt(argc, argv, "n:s:T:h")) != -1) {
        switch (ch) {
        case 'n':
            *nstep = atoi(optarg);
            break;
        case 's':
            *s = atof(optarg);
            break;
        case 'T':
            *kT = atof(optarg);
            break;
        case 'h':
        case '?':
            usage(argv[0]);
        }
    }
}

int main(int argc, char *argv[]) {
    // seed random generator
    srand(time(NULL));

    // parameters
    int nstep = 10000;
    int ground = 0;    // the times of particle stays in ground state
    int excited = 0;   // the times of particle stays in excited state
    double x = 0.0, y = 0.0;
    double s = 0.1;
    double kT = 1.0;
    const char *filename = "output.dat";

    getArgs(argc, argv, &nstep, &s, &kT);
    MC_walker m = MC_walker(x, y, s, kT);
    FILE *fp = fopen(filename, "w");

    for (int i=0; i<nstep; ++i) {
        m.walk();
        m.output(fp, i);
        int state = m.state();

        if (state == 0)
        ground++;
        else if (state == 1)
        excited++;
    }
    fclose(fp);
    
    cout << "The temperature of the system: kT = " << kT << "\n" <<\
    "Probability of ground state: " << double (ground * 1.0 / nstep) << endl;
    return 0;
}
