#ifndef USE_H
#define USE_H
#include <cstdio>
#include <unistd.h>

using namespace std;

// the usage
void usage(char *program) {
    fprintf(stderr, "\nProgram Usage:\n%s\n", program);
    fprintf(stderr,
            "     [ -n  10000 ]  number of steps per run, default 10000\n");
    fprintf(stderr,
            "     [ -m  1.0 ]    mass of the atom, default 1.0\n");
    fprintf(stderr,
            "     [ -T  1.0 ]    temperature kT of the system, default 1.0\n");
    fprintf(stderr,
            "     [ -g  0.1 ]    coefficient of viscosity gamma, default 0.1\n");
    fprintf(stderr,
            "     [ -t  0.1 ]    time interval Δt of the system, default 0.1\n");
    fprintf(stderr, "     [ -h ]         display this information\n");
    fprintf(stderr, "\n");
    exit(1);
}

// Get system arguments from command line
void getArgs(int argc, char **argv, int *nstep, double *mass, double *kT, double *gamma, double *dt) {
    char ch;
    while ((ch = getopt(argc, argv, "n:e:T:h")) != -1) {
        switch (ch) {
        case 'n':
            *nstep = atoi(optarg);
            break;
        case 'm':
            *mass = atof(optarg);
            break;
        case 'T':
            *kT = atof(optarg);
            break;
        case 'g':
            *gamma = atof(optarg);
            break;
        case 't':
            *dt = atof(optarg);
            break;
        case 'h':
        case '?':
            usage(argv[0]);
        }
    }
}

#endif