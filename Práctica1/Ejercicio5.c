#include <stdlib.h>
#include <stdio.h>

int main(){
    int x[8] = {10, 20, 30, 40, 50, 60, 70, 80};
    printf("%d, %p \n", *(x+2), (x+2));
}