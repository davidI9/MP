#include <stdlib.h>
#include <stdio.h>
#include "Ejercicio6funct.c"

int main(){
    //Primera versión de la función media
    printf("%d \n",media(6, 4));

    //Segunda version de la funcion media (por referencia)
    float resultado = 0;
    media_referencia(&resultado, 4, 6);
    printf("%f \n", (resultado));

}