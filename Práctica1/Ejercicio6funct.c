#include "Ejercicio6prot.h"

int media(int num1, int num2){
    return (num1+num2)/2;
}

void media_referencia(float* resultado, int num1, int num2){
    *resultado = (num1+num2)/2;
}