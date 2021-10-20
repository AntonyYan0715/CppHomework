#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#define N 300     /* number of particles */

// Return a uniform random number in [a,b)
double unirand(double a, double b){
    return a + (b-a) * (rand() / (float)RAND_MAX);
}

// Calculate the distance between particle_1 and particle_2 with periodic boundary condition
double distance(double L, double x1, double y1, double x2, double y2){
    double dx, dy;

    dx = fabs(x1 - x2);
    if (L-dx < dx)
    dx = L-dx;

    dy = fabs(y1 - y2);
    if (L-dy < dy)
    dy = L-dy;

    return sqrt(dx*dx + dy*dy);
}

// Calculate the direction vector from particle_1 to particle_2
double direction(double L, double x1, double y1, double x2, double y2){
    double dx, dy, angle;

    dx = x2 - x1;
    if (L-fabs(dx) < fabs(dx)){
        if (dx > 0)
        dx = dx-L;
        else
        dx = L+dx;
    }

    dy = y2 - y1;
    if (L-fabs(dy) < fabs(dy)){
        if (dy > 0)
        dy = dy-L;
        else
        dy = L+dy;
    }

    angle = atan2(dy, dx);
    return angle;
}

// Calculate the pairwise distance between all particles
void pair_aistance(double L, double Dist[N][N], double x[N], double y[N]){
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            Dist[i][j] = distance(L, x[i], y[i], x[j], y[j]);
}

// Calculate the average angle of particles in neighborhood
// Add a noise term Δtheta, a temperaturelike variable
void cal_angle(double Dist[N][N], double theta[N], double x[N], double y[N], double r_r, double r_a, double r_c, double eta, double L){
    double repulsion[N], alignment[N], cohesion[N];

    for (int i=0; i<N; i++){
        int count1 = 0, count2 = 0, count3 = 0;
        for (int j=0; j<N; j++){
            if (Dist[i][j] > 0 && Dist[i][j] <= r_r){
                repulsion[count1] = direction(L, x[i], y[i], x[j], y[j]) - M_PI;
                count1 += 1;
            }
            else if (Dist[i][j] > r_r && Dist[i][j] <= r_a){
                alignment[count2] = theta[j];
                count2 += 1;
            }
            else if (Dist[i][j] > r_a && Dist[i][j] <= r_c){
                cohesion[count3] = direction(L, x[i], y[i], x[j], y[j]);
                count3 += 1;
            }
            else if (Dist[i][j] == 0){
                alignment[count2] = theta[j];
                count2 += 1;
            }
        }

        double mean_sin = 0.0, mean_cos = 0.0, mean_angle;
        if (count1 == 0){
            for (int k=0; k<count2; k++){
                mean_sin += sin(alignment[k]);
                mean_cos += cos(alignment[k]);
            }
            for (int k=0; k<count3; k++){
                mean_sin += sin(cohesion[k]);
                mean_cos += cos(cohesion[k]);
            }
            mean_sin = mean_sin / (count2 + count3);
            mean_cos = mean_cos / (count2 + count3);
        }
        else if (count1 > 0){
            for (int k=0; k<count1; k++){
                mean_sin += sin(repulsion[k]);
                mean_cos += cos(repulsion[k]);
            }
            mean_sin = mean_sin / count1;
            mean_cos = mean_cos / count1;
        }

        mean_angle = atan2(mean_sin, mean_cos) + eta * unirand(-0.5, 0.5);
        if (fabs(mean_angle - theta[i]) < M_PI / 6)
        theta[i] = mean_angle;
        else
        theta[i] = ((mean_angle-theta[i]) / fabs(mean_angle - theta[i])) * (M_PI/6) + theta[i];
    }
}

// Write the positions and velocities of particles to a file
void filewriter(double x[N], double y[N], double v_x[N], double v_y[N], int iter){
    FILE *fp;
    char filename[20];
    sprintf(filename, "./data/%05d.csv", iter);

    fp = fopen(filename, "w+");
    if (fp == NULL){
        printf("Can't open\n");
        exit(1);
    }

    for (int i=0; i<N; i++){
        fprintf(fp, "%lf, %lf, %lf, %lf\n", x[i], y[i], v_x[i], v_y[i]);
    }
    fclose(fp);
}

// Calculate the absolute value of the average normalized velocity
double cal_norm_velocity(double v, double v_x[N], double v_y[N]){
    double v_a, v1=0.0, v2=0.0;
    for (int i=0; i<N; i++){
        v1 += v_x[i];
        v2 += v_y[i];
    }

    v_a = sqrt(v1*v1 + v2*v2);
    v_a = v_a / (N*v);
    return v_a;
}

//////////////////////////////////////////////////////////////////////////////////
int main(){
    /*
     * x[i], y[i]: the x,y position of i-th particle
     * v_x[i], v_y[i]: the v_x,v_y velocity of i-th particle
     * theta[i]: the angle of i-th particle
     * Dist[i][j]: the pairwise distance between i-th particle and j-th particle
     * 
     * iter: number of iterations
     * L: size of system
     * v: speed of particles
     * dt: time interval
     * eta: noise term
     * r_r: repulsion radius
     * r_a: alignment radius
     * r_c: cohesion radius
     * 
     */
    int iter=300;
    double x[N], y[N], v_x[N], v_y[N], theta[N], Dist[N][N];
    double L=5.0, v=0.06, dt=0.1, eta=0.1, r_r=0.1, r_a=0.5, r_c=2.0;
    
    srand(time(NULL));

    // Make "data" directory to store positions and velocities data
    mkdir("data",0755);

    for (int i=0; i<N; i++){
        theta[i] = unirand(-M_PI, M_PI);
        x[i] = unirand(0.0, L);
        y[i] = unirand(0.0, L);
        v_x[i] = v * cos(theta[i]);
        v_y[i] = v * sin(theta[i]);
    }

    // Start Vicsek model
    for (int i=0; i<iter; i++){
        filewriter(x, y, v_x, v_y, i);

        // Calculate the pairwise distance
        pair_aistance(L, Dist, x, y);


        // Calculate the angle
        cal_angle(Dist, theta, x, y, r_r, r_a, r_c, eta, L);

        // Update the positions and velocities
        for (int i=0; i<N; i++){
            x[i] += v_x[i] * dt;
            y[i] += v_y[i] * dt;
            v_x[i] = v * cos(theta[i]);
            v_y[i] = v * sin(theta[i]);
        }

        // Periodic boundary condition
        for (int i=0; i<N; i++){
            x[i] = fmodl(x[i] + L, L);
            y[i] = fmodl(y[i] + L, L);
        }
    }
    return 0;
}