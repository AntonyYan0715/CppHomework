#include <iostream>
#include <cmath>
#include <unistd.h>
#define PI 3.1415926

using namespace std;

typedef double point[2];
point vertex[3] = {{-0.8660254, -0.5}, {0.8660254, -0.5}, {0.0, 1.0}};
double theta = 0.0;

void showPoint(point firstPoint) {
    cout << "(" << firstPoint[0] << ", " << firstPoint[1] << ")" << endl;
}

void divide(int n, point firstPoint, point secondPoint, double theta) {
    if (n > 0) {
        point newPoint[3];                 // the 3 new points
        double x_length, y_length, length; // calculate the side length of new triangle
        x_length = secondPoint[0] - firstPoint[0];
        y_length = secondPoint[1] - firstPoint[1];
        length = sqrt(x_length * x_length + y_length * y_length) / 3;

        // calculate the coordinates of new triangle's vertexs
        newPoint[0][0] = firstPoint[0] + x_length / 3;
        newPoint[0][1] = firstPoint[1] + y_length / 3;
        newPoint[2][0] = secondPoint[0] - x_length / 3;
        newPoint[2][1] = secondPoint[1] - y_length / 3;

        newPoint[1][0] = length * cos(theta - PI/3) + newPoint[0][0];
        newPoint[1][1] = length * sin(theta - PI/3) + newPoint[0][1];

        // recursion
        divide(n-1, firstPoint, newPoint[0], theta);
        divide(n-1, newPoint[0], newPoint[1], theta - PI/3);
        divide(n-1, newPoint[1], newPoint[2], theta + PI/3);
        divide(n-1, newPoint[2], secondPoint, theta);
    }

    else
    showPoint(firstPoint);
}

// the usage
void usage(char *program) {
    fprintf(stderr, "\nProgram Usage:\n%s\n", program);
    fprintf(stderr,
            "     [ -n  1 ]      rank of the Koch snowflake, default 0\n");
    fprintf(stderr, "     [ -h ]         display this information\n");
    fprintf(stderr, "\n");
    exit(1);
}

// get system arguments from command line
void getArgs(int argc, char **argv, int *n) {
    char ch;
    while ((ch = getopt(argc, argv, "n:h")) != -1) {
        switch (ch) {
        case 'n':
            *n = atoi(optarg);
            break;
        case 'h':
        case '?':
            usage(argv[0]);
        }
    }
}

int main(int argc, char** argv) {
    int n = 0;
    getArgs(argc, argv, &n);
    
    divide(n, vertex[0], vertex[1], theta);
    divide(n, vertex[1], vertex[2], theta + 2*PI/3);
    divide(n, vertex[2], vertex[0], theta - 2*PI/3);
    return 0;
}