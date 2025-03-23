#include <stdio.h>
#include <stdlib.h>

int main(){
    char letra = 'a';
    char* ptrc;
    ptrc = &letra;
    *ptrc = 'A';

    printf("%c", letra);

    return 0;
}