#include <math.h>
#include <stdio.h>
#include "Ejercicio7prot.h"

void estadisticasVector(int vector[], double* media, double* varianza, double* desvTip, int n){
    double cont=0, cont2=0;

    printf("[");
    for (int i = 0; i < n; i++)
    {
        cont += vector[i];
        cont2 += pow(vector[i], 2);
        printf("%d, ", vector[i]);
    }
    printf("]\n");
    
    *media = cont/n;
    *varianza = ((cont2/n) - ((*media)*(*media)));
    *desvTip = sqrt(*varianza);
}