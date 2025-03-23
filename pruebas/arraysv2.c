#include <stdlib.h>
#include <stdio.h>

int main(){
    int v1[5] = {2, 3, 4, 3, 5};
    int* puntv = &v1[1];
    printf("%d", *puntv);

}