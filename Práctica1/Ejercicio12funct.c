#include <stdio.h>
#include <stdlib.h>
#include "Ejercicio12prot.h"

void rfra(Fraccion* variable){
    printf("Introduce el numerador:\n");
    scanf("%d", &(variable -> numerador));
    printf("Introduce el denominador:\n");
    scanf("%d", &(variable -> denominador));
};

void imfra(Fraccion* variable){
    printf("El numerador es %d y el denominador es %d.\n", variable -> numerador, variable -> denominador);
};

void multfra(Fraccion* res, Fraccion* var1, Fraccion* var2){
    (res -> numerador) = (var1 -> numerador)*(var2 -> numerador);
    (res -> denominador) = (var1 -> denominador)*(var2 -> denominador);
};