#include <stdio.h>
#include <stdlib.h>
#include "Ejercicio2funct.c"

int main(){
    int n=0, num=0;
    int** index = (int**)calloc(2, sizeof(int*));

    printf("Introduce el tamaño del vector dinamico:\n");
    scanf("%d", &n);

    int* vector = (int*)calloc(n, sizeof(int));
    for(int i=0; i<n; i++){
        printf("Introduce el valor %d: ", i+1);
        scanf("%d", vector+1);
    }

    printf("Sobre que valor quieres dividir el vector?");
    scanf("%d", &num);

    index = divVect(vector, num, n);

    //Se podría decir que el código está incompleto porque no está hecho para que imprima la matriz con los vectores divididos 
    //(Además que estos vectores están sobredimensionados, pero da igual porque es para aprender)
    
    free(index);
    free(vector);
}