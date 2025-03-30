#include <stdlib.h>
#include <stdio.h>
#include "Ejercicio3funct.c"

int main(){
    
    int nFil, nCol;

    printf("Introduce el numero de filas de la matriz:\n");
    scanf("%d", &nFil);
    
    printf("Introduce el numero de columnas de la matriz:\n");
    scanf("%d", &nCol);

    int** matriz = reservarMemoria(nFil, nCol);

    rellenaMatriz(matriz, nFil, nCol);

    imprimeMatriz(matriz, nFil, nCol);

    int* columnaMinima = minCol(matriz, nFil, nCol);
    
    liberarMemoria(&matriz, nFil);

}