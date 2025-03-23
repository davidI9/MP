#include <stdlib.h>
#include <stdio.h>
#include "Ejercicio10prot.h"

void leeVector(double vector[], int n){
    for(int i = 0; i<n; i++){
        printf("Introduce el termino numero %d del vector:\n", i+1);
        scanf("%lf", &vector[i]);
    }
}

void escribeVector(double vector[], int n){
    for(int i=0; i<n; i++){
        printf("%lf ", vector[i]);
    }
}

double sumaPositivos(double vector[], int n){
    double suma=0;
    for(int i = 0; i<n; i++){
        if(vector[i]>0){
            suma+=vector[i];
        }
    }
    return suma;
}