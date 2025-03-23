#include <stdlib.h>
#include <stdio.h>
#include "Ejercicio7funct.c"

int main(){
    int nelementos = 10;
    double desvTip, media, varianza;
    int vector[10] = {2.0, 6.0, 4.0, 5.0, 9.0, 5.0, 4.0, 7.0, 10.0, 5.0};

    estadisticasVector(vector, &media, &varianza, &desvTip, nelementos);
    printf("Media: %f \nVarianza: %f \nDesviación Típica: %f\n", media, varianza, desvTip);

}