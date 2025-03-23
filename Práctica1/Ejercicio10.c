/********************************************************************

Codifica un programa que usando funciones y aritmética de punteros:
• Lea un vector de elementos tipo double (leeVector).
• Imprima los datos del vector por pantalla (escribeVector).
• Sume los elementos mayores que cero del vector (sumaPositivos).

********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "Ejercicio10funct.c"

int main(){
    int n;
    double res;
    printf("Introduce el tamaño del vector:\n");
    scanf("%d", &n);

    if(n<=0){
        printf("Error: el tamaño del vector debe ser mayor o igual que uno.\n");
        return 1;
    }

    double* vector = (double*)calloc(n, sizeof(double));
    if(vector == NULL){
        printf("Error: el vector no se ha inicializado correctamente.\n");
        return 1;
    }
    leeVector(vector, n);
    escribeVector(vector, n);
    printf("\n%lf\n", res = sumaPositivos(vector, n));

    free(vector);
}