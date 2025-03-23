#include <stdio.h>
#include <stdlib.h>
#include "Ejercicio8funct.c"

int  main(){
    //este char se puede modificar evidentemente, para probar con otras frases y tal
    char cadena[10]= "123 Hola";
    int nNums=0, nMayus=0, nMinus=0, nEspc=0, n=10;
    estadisticasCadena(cadena, &nNums, &nMayus, &nMinus, &nEspc, n);
    printf("Hay %d numeros, %d mayusculas, %d minusculas y %d espacios\n", nNums, nMayus, nMinus, nEspc);
}