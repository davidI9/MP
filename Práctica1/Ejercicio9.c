#include <stdio.h>
#include <stdlib.h>
#include "Ejercicio9funct.c"

int main(){
    int n=0, X;
    Monomio* vector = NULL;
    Monomio gmax, gmin;

    //imprimirMonomio(&termino1);

    printf("¿Cuántos monomios quieres introducir en el vector de monomios?\n");
    scanf("%d", &n);
    if(n<=0){
        printf("El tamaño del vector no puede ser menor o igual que 0.\n");
        return 1;
    }


    vector=(Monomio*)calloc(n, sizeof(Monomio));
    if(vector == NULL){
        printf("La memoria no se ha asignado correctamente.\n");
        return 1;
    }


    for (int i = 0; i < n; i++){
        leerMonomio(&vector[i]);
    }

    for (int i = 0; i < n; i++){
        imprimirMonomio(vector[i]);
    }

    maxmin(vector, &gmax, &gmin, n);
    imprimirMonomio(gmax);
    imprimirMonomio(gmin);

    printf("¿Que valor de x quieres evaluar?\n");
    scanf("%d", &X);
    printf("%d\n", polinomio(vector, X, n));

    free(vector);
    return 0;
}