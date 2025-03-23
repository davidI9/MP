#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Ejercicio8prot.h"

void estadisticasCadena(char cadena[], int* nNums, int* nMayus, int* nMinus, int* nEspc, int n){
    for(int i = 0; i<n; i++){
        if(isdigit(cadena[i])!=0){
            (*nNums)++;
        }
        else if(isupper(cadena[i])!=0){
            (*nMayus)++;
        }
        else if(islower(cadena[i])!=0){
            (*nMinus)++;
        }
        else if(cadena[i]==' '){
            (*nEspc)++;
        }
    }
}