#include <stdio.h>
#include <stdlib.h>
#include "Ejercicio4prot.h"
#include <time.h>


float* reservarMemoria(int nFil, int nCol){

    float* matriz = (float*)calloc(nFil * nCol, sizeof(float));

    return matriz;

}

void rellenaMatriz(float* matriz, int nFil, int nCol){

    srand(time(NULL));

    for(int i=0; i<nFil; i++){

        for(int j=0; j<nCol; j++){

            matriz[i * nCol + j] = ((rand() % 100) * 0.01);

        }

    }

}

void imprimeMatriz(float* matriz, int nFil, int nCol){

    for(int i=0; i<nFil; i++){

        for(int j=0; j<nCol; j++){

            printf("%f ", matriz[i * nCol + j]);

        }

        printf("\n");

    }

}


float max(float* v, int n){

    float mayor = *v;

    for(int i = 0; i<n; i++){

        if(v[i]>mayor){
            mayor = v[i];
        }

    }

    return mayor;

}

float* maxFil(float* matriz, int nFil, int nCol){

    float* maximosFila = (float*)calloc(nFil, sizeof(float));
    
    for(int i = 0; i < nFil; i++){

        maximosFila[i] = max(&matriz[i * nCol], nCol);
        printf("%f\n", maximosFila[i]);

    }

    return maximosFila;

}

void liberarMemoria(float** matriz){

    free(*matriz);

    matriz = NULL;

}
