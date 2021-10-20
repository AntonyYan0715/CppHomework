#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define PI 3.1415926

// Return a uniform random number in [a,b)
float unirand(float a, float b) {
    return a + (b-a) * (rand() / (float)RAND_MAX);
}

// Return the distance from the start point
float dist(float x, float y) {
    return sqrt(x*x + y*y);
}

// Output the data
void filewriter(FILE *fp, int istep, float x, float y) {
    fprintf(fp, "%10d %10.2f %10.2f %10.2f\n", istep, x, y, dist(x, y));
}

// Get the step: 50% one step, 50% half step
void getStep(float *step1, float *step2) {
    float angle, prob;
    angle = unirand(0, 2*PI);
    *step1 = sin(angle);
    *step2 = cos(angle);

    prob = unirand(0, 1);
    if (prob < 0.5) {
        *step1 /= 2;
        *step2 /= 2;
    }
}

// Run the step: 80% run, 20% stay
void runStep(float *x, float *y, float step1, float step2) {
    float prob = unirand(0, 1);
    if (prob < 0.8) {
        *x += step1;
        *y += step2;
    }
}

// the usage
void usage(char *program) {
    fprintf(stderr, "\nProgram Usage:\n%s\n", program);
    fprintf(stderr,
            "     [ -n  1000000 ]    number of steps per run, default 10000\n");
    fprintf(stderr,
            "     [ -o output.dat ]  the output file, default: output.dat\n");
    fprintf(stderr, "     [ -h ]             display this information\n");
    fprintf(stderr, "\n");
    exit(1);
}

// Get system arguments from command line
void getArgs(int argc, char **argv, int *nstep, char **filename) {
    char ch;
    while ((ch = getopt(argc, argv, "n:o:h")) != -1) {
        switch (ch) {
        case 'n':
            *nstep = atoi(optarg);
            break;
        case 'o':;
            char *new_name = optarg;
            *filename = new_name;
            break;
        case 'h':
            usage(argv[0]);
        case '?':
            usage(argv[0]);
        }
    }
}

int main(int argc, char *argv[]) {
    // Seed random generator
    srand(time(NULL));

    // parameters
    int nstep = 10000;
    char *filename = "output.dat";
    getArgs(argc, argv, &nstep, &filename);

    // the initial state
    float x = 0.0, y = 0.0;
    FILE *fp = fopen(filename, "w");
    filewriter(fp, 0, x, y);

    // walking...
    int i;
    for (i = 1; i < nstep; ++i) {
        float step1, step2;
        getStep(&step1, &step2);
        runStep(&x, &y, step1, step2);
        filewriter(fp, i, x, y);
    }
    fclose(fp);
}