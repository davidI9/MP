#include <stdlib.h>
#include <stdio.h>

int main(){
    int valor = 100;
    int** ptvalor;
    *ptvalor = &valor;
    printf("%p \n", ptvalor);
    printf("%p \n", *ptvalor);
}