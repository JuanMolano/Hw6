//
//  Burgers.c
//
//
//  Created by Juan Pablo Molano on 3/11/15.
//
//


#include "stdio.h"
#include <stdlib.h>
#include <math.h>


float *linspace(int n);
void print_array(float *array, int n_puntos);
float **matrix_ones(int filas, int columnas);
void IC(float **array);
void print_matrix(float **array, int n_dim);
void copy(float **origen, float **destino, int n_puntos);


int main(){
    
    int nx = 41;
    int ny = 41;
    int nt = 500;
    float dx = 2.0/(nx-1);
    float dy = 2.0/(ny -1);
    float sigma = 0.0009;
    float nu = 0.01;
    float dt = sigma*dx*dy/nu;
    float **u;
    float **v;
    float **un;
    float **vn;
    
    int i;
    int j;
    int k;
    
    
    u = matrix_ones(nx,ny);
    v = matrix_ones(nx,ny);
    un = matrix_ones(nx,ny);
    vn = matrix_ones(nx,ny);
    
    IC(u);
    IC(v);
    
    
    
    for(i=0;i<nt;i++){
        
        copy(u,un,nx);
        copy(v,vn,ny);
        
        for (j=1; j<nx-1; j++) {
            for (k=1; k<ny-1; k++){
                
                u[j][k] = un[j][k] - (dt/dx)*un[j][k]*(un[j][k]-un[j-1][k]) - (dt/dy)*vn[j][k]*(un[j][k]-un[j][k-1]) + (nu*dt/pow(dx,2))*(un[j+1][k]-2*un[j][k]+un[j][k]) +(nu*dt/pow(dy,2))*(un[j][k+1] - 2*un[j][k]+un[j][k-1]) ;
                
                
                v[j][k] = vn[j][k] - (dt/dx)*un[j][k]*(vn[j][k]-vn[j-1][k]) - (dt/dy)*vn[j][k]*(vn[j][k]-vn[j][k-1]) + (nu*dt/pow(dx,2))*(vn[j+1][k]-2*vn[j][k]+vn[j-1][k])+ (nu*dt/pow(dy,2))*(vn[j][k+1] - 2*vn[j][k]+vn[j][k-1]);
                
                
                
                
            }
        }
        
        print_matrix(u,nx);
        print_matrix(v,ny);
        
    }
    
    
    return 0;
    
}



float **matrix_ones(int filas, int columnas){
    
    float **x;
    x = (float **)malloc(filas*sizeof(float*));
    int i;
    int j;
    
    for (i=0;i<filas;i++){
        
        x[i] = (float*)malloc(columnas*sizeof(float));
        
    }
    
    for (i=0;i<filas;i++){
        for (j=0;j<filas;j++){
            x[i][j] = 1.0;
        }
    }
    
    
    return x;
    
}


void copy(float **origen, float **destino, int n_puntos){
    int i;
    int j;
    for(i=0;i<n_puntos;i++){
        
        for(j=0;j<n_puntos;j++){
            destino[i][j] = origen[i][j];
            
        }
    }
}


void IC(float **array){
    int i;
    int j;
    for (i=10;i<20;i++){
        for (j=10;j<20;j++){
            array[i][j] = 2.0;
        }
    }
    
}


void print_matrix(float **array, int n_dim){
    
    int i;
    int j;
    
    
    for (i=0; i<n_dim; i++)
    {
        
        
        for (j=0; j<n_dim; j++){
            if( j == 0 ){
                printf("%f", array[i][j] );
            }
            else{
                printf("\t%f", array[i][j] );
            }
            
        }
        printf("\n");
    }
    
    
}

void print_array(float *array, int n_puntos){
    int i;
    for(i=0;i<n_puntos;i++){
        printf("%f \n", array[i]);
    }
}


float *linspace(int n){
    float *array;
    int i;
    if(!(array = malloc(n * sizeof(float)))){
        printf("Problema en reserva\n");
        exit(1);
    }
    for(i=0;i<n ;i++){
        array[i] = i*2.0/(n-1);
    }
    return array;
}
