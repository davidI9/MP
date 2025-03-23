#include <stdlib.h>
#include <stdio.h>

int main(){
    int v[3];
    int* ptrv;

    ptrv = v;
    printf("%p \n%p \n", ptrv, &v[0]); /*Son iguales*/
    
}