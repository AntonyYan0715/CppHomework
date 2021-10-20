#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <unistd.h>
#define PI 3.1415926
#define N 100  // size of the lattice

using namespace std;

// Return a uniform random integer in [a,b)
double unirand(int a, int b){
    return (rand() % (b-a))+ a;
}

class Ising {
    public:
    int lattice[N][N];
    double epsilon;
    double kT;

    Ising(double e, double T) {
        epsilon = e;
        kT = T;

        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++)
            lattice[i][j] = 1;
        }
    }

    int neighbor(int x, int y);
    void flip();
    int total_M();
    void output(FILE *fp, int istep);
};

// Calculate the total magnetization of [x,y]'s four neighbors
int Ising::neighbor(int x, int y) {
    int M;
    int left, right, up, down;

    // Periodic boundary condition
    if (x == 0)
    left = N-1;
    else
    left = x-1;

    if (x == N-1)
    right = 0;
    else
    right = x+1;

    if (y == N-1)
    up = 0;
    else
    up = y+1;

    if (y == 0)
    down = N-1;
    else
    down = y-1;

    M = lattice[left][y] + lattice[right][y] + lattice[x][up] + lattice[x][down];
    return M;
}

// Flip a random spin
void Ising::flip() {
    int x = unirand(0, N);
    int y = unirand(0, N);
    int M = neighbor(x, y);
    double deltaE = 2 * epsilon * lattice[x][y] * M;

    if (deltaE <= 0)
        lattice[x][y] = -lattice[x][y];
    else if ((rand() / (float)RAND_MAX) < exp(-deltaE / kT))
        lattice[x][y] = -lattice[x][y];
}

// Calculate the total magnetization
int Ising::total_M() {
    int M = 0;

    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j)
        M += lattice[i][j];
    }
    return M;
}

// Output data to the file
void Ising::output(FILE *fp, int istep) {
    fprintf(fp, "%10d   Total magnetization: %10d\n", istep, total_M());
}

// the usage
void usage(char *program) {
    fprintf(stderr, "\nProgram Usage:\n%s\n", program);
    fprintf(stderr,
            "     [ -n  10000000 ]  number of steps per run, default 10000000\n");
    fprintf(stderr,
            "     [ -e  1.0 ]       the value of epsilon, default 1.0\n");
    fprintf(stderr,
            "     [ -T  1.0 ]       temperature kT of the system, default 1.0\n");
    fprintf(stderr, "     [ -h ]            display this information\n");
    fprintf(stderr, "\n");
    exit(1);
}

// Get system arguments from command line
void getArgs(int argc, char **argv, int *nstep, double *epsilon, double *kT) {
    char ch;
    while ((ch = getopt(argc, argv, "n:e:T:h")) != -1) {
        switch (ch) {
        case 'n':
            *nstep = atoi(optarg);
            break;
        case 'e':
            *epsilon = atof(optarg);
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
    int nstep = 10000000;
    double epsilon = 1.0;
    double kT = 1.0;
    const char *filename = "output.dat";

    getArgs(argc, argv, &nstep, &epsilon, &kT);
    Ising is = Ising(epsilon, kT);
    FILE *fp = fopen(filename, "w");

    for (int i; i<nstep; ++i) {
        is.flip();
        is.output(fp, i);
    }
    fclose(fp);
    cout << "Total magnetization: " << is.total_M() << endl;
    return 0;
}
