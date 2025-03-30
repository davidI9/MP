#include <stdlib.h>
#include <stdio.h>
#include "Ejercicio3prot.h"
#include <time.h>


//crea la matriz :)

int** reservarMemoria(int nFil, int nCol){

    int** matriz = (int**)calloc(nFil, sizeof(int*));

    for(int i=0; i<nCol; i++){

        *(matriz+i) = (int*)calloc(nCol, sizeof(int));

    }

    return matriz;
}

//inicializa la matriz de forma aleatoria

void rellenaMatriz(int** matriz, int nFil, int nCol){

    srand(time(NULL));

    for(int i=0; i<nFil; i++){

        for(int j=0; j<nCol; j++){
 
            *(*(matriz+i)+j) = rand()%20;
 
        }
 
    }

}

//imprime la matriz xd

void imprimeMatriz(int** matriz, int nFil, int nCol){
 
    for(int i=0; i<nFil; i++){
 
        for(int j=0; j<nCol; j++){
 
            printf("%d ", *(*(matriz+i)+j));
 
        }
 
        printf("\n");
 
    }

}

//devuelve el valor mas pequeño de un vector

int min(int* v, int n){

    int aux = *v;

    for(int i=0; i<n; i++){

        if(*(v+i)<aux){

            aux = *(v+i);
        
        }
        
    }

    return(aux);

}

//devuelve un vector con los valores mas pequeños de cada columna

int* minCol(int** matriz, int nFil, int nCol){

    int* column = (int*)calloc(nFil, sizeof(int));

    for(int i=0; i<nFil; i++){

        *(column+i) = min(*matriz, nCol);

    }

    return column;

}

//libera la memoria de la matriz xd, está "incompleto" porque según el ejercicio hay que poner algo en NULL -_-

void liberarMemoria(int*** matriz, int nFil){

    for(int i=0; i<nFil; i++){

        free(*(*matriz+i));

    }

    free(*matriz);

}