#include <stdio.h>
#include <stdlib.h>
#include "Ejercicio2prot.h"

int** divVect(int vector[],int num, int n){

    int** index = (int**)calloc(2, sizeof(int*));
    index[0] = (int*)calloc(n, sizeof(int));
    index[1] = (int*)calloc(n, sizeof(int));

    int j=0, k=0;
    for(int i=0; i<n; i++){
        if(vector[i]>num){
            index[0][j] = vector[i];
            j++;
        } else {
            index[1][k] = vector[i];
            k++;
        }
    }
    
    return index;
}