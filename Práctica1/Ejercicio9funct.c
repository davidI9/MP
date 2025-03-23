#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Ejercicio9prot.h"

void leerMonomio(struct Monomio *termino){
    printf("Introduce el coeficiente del monomio: \n");
    scanf("%d", &termino -> coeficiente);
    printf("Introduce el grado del monomio: \n");
    scanf("%d", &termino -> grado);
}

void imprimirMonomio(Monomio termino){
    printf("%dx^%d.\n", termino.coeficiente, termino.grado);
}

void maxmin(Monomio vector[], Monomio *gmax, Monomio *gmin, int n){
    *gmax = vector[0];
    *gmin = vector[0];
    for(int i = 1; i<n; i++){
        if((gmax->grado)<(vector[i].grado)){
            *gmax=vector[i];
        }
        if((gmin->grado)>(vector[i].grado)){
            *gmin=vector[i];
        }
    }
}

int polinomio(Monomio vector[], int X, int n){
    int suma=0;
    for(int i=0; i<n; i++){
        suma+=((vector[i].coeficiente)*(pow(X, vector[i].grado)));
    }
    return suma;
}