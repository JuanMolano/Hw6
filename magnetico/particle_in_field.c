//
//  particle_in_field.c
//  
//
//  Created by Juan Pablo Molano on 5/11/15.
//
//

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define USAGE "./particle_in_field"


double rk4(double(*f)(double, double), double dt, double x, double dx);
double campox(double dy, double Bz);
double campoy(double z, double Bx);
double campoz(double dx, double By);



int main(int argc, char **argv){
    
  
    double k = atof(argv[1]);
    double alpha = atof(argv[2]);
    double r_t = 6378.1 * 1000;
    double pi = M_PI;
    double b_0 = 0.00003;
    double m = 1.672*pow(10,-2);
    double q = 1.602176487 / pow(10,19);
    double c = 300000000;
    double v = sqrt( pow(c,2) - (m*pow(c,4))/(k + m*pow(c,2)));
    double *x;
    double *dx;
    double *y;
    double *dy;
    double *z;
    double *dz;
    double x0 = 2*r_t, x1 = v*sin(alpha), y1 = v*cos(alpha);
    int i, dt = 1, n = 100;
    //La magnitud de la velocidad será constante debido a que el campo magnético no genera trabajo sobre el protón
    float g= k/(m*pow(c,2)) +1 ;
    
    x = malloc(sizeof(double) * n);
    y = malloc(sizeof(double) * n);
    dx = malloc(sizeof(double) * n);
    dy = malloc(sizeof(double) * n);
    z = malloc(sizeof(double) * n);
    dz = malloc(sizeof(double) * n);
    
    
    
    for (i = 0; i < n; i++){
        x[i] = rk4(campox, dt, x0 , x1);
    }
    for (i = 0; i < n; i++){
        y[i] = rk4(campoy, dt, 0, y1);
    }
    for (i = 0; i < n; i++){
        z[i] = rk4(campoz, dt, 0 ,0);
    }

 
    
    for (i = 0; i < n; i ++) {
       
        printf("%g\t%g\t%g\n", x[i], y[i], z[i]);
    }
    
  

    
    return 0;
}




double rk4(double(*f)(double, double), double dt, double x, double dx)
{
  
    
    double k1 = dt * f(x, dx),
    k2 = dt * f(x + dt / 2, dx + k1 / 2),
    k3 = dt * f(x + dt / 2, dx + k2 / 2),
    k4 = dt * f(x + dt, dx + k3 );
    
    return dx + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
   
}

double campox(double dy, double Bz){
    
    return 1;
}

double campoy(double z, double Bx){
    return 2;
}

double campoz(double dx, double By){
    return 3;
}


