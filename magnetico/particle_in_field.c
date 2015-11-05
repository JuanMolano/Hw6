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

float *reserva(int n);
void print_array(float *array, int n);


int main(int argc, char **argv){
    
    float *x;
    float *y;
    float *z;
    float k = atof(argv[1]);
    float alpha = atof(argv[2]);
    float b_0 = 0.00003;
    float r_t = 6378.1 * 1000;
    float pi = M_PI;
    float m = 938.272013;
    float c = 300000000;
    double q = 1.602176487 / pow(10,19);
    int n = 100;
    
    x = reserva(n);
    y = reserva(n);
    z = reserva(n);
    
    x[0] = 2*r_t;
    
    printf("%f\n", alpha);
    
    
    
    
    
}


float *reserva(int n){
    float *array;
    int i;
    if(!(array = malloc(n * sizeof(float)))){
        printf("Problema en reserva\n");
        exit(1);
    }
    for(i=0;i<n;i++){
        array[i] = 0.0;
    }
    return array;
}

void print_array(float *array, int n){
    int i;
    for(i=0;i<n;i++){
        printf("%g \n", array[i]);
    }
}

typedef struct{
    float i,j,k;
}Vector;

vector crossProduct(Vector a,Vector b){
    
    Vector c = {a.j*b.k - a.k*b.j, a.k*b.i - a.i*b.k, a.i*b.j - a.j*b.i};
    
    return c;
    


