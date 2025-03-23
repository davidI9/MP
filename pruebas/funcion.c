#include <stdlib.h>
#include <stdio.h>

void sqr(int* n){
    *n = ((*n) * (*n));
};

int main(){
    int numero = 3;
    sqr(&numero);
    printf("%d \n", numero);
};