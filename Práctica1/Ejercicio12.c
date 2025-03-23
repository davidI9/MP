#include <stdio.h>
#include <stdlib.h>
#include "Ejercicio12funct.c"

int main(){
    int n=0;
    Fraccion resultao;
    printf("Introduce el tamaño del vector que quieres almacenar\n");
    scanf("%d", &n);

    Fraccion* vector = (Fraccion*)calloc(n, sizeof(Fraccion));
    for(int i=0; i<n; i++){
        rfra(vector+i);
    }

    if(n>=2){
        multfra(&resultao, vector, vector+1);
    }

    imfra(&resultao);

    free(vector);
}