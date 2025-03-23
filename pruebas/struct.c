#include <stdlib.h>
#include <stdio.h>

int main(){
    struct punto{
        int x;
        int y;
    };
    
    struct punto a;
    struct punto* p;
    p=&a;

    (*p).x = 10;
    (*p).y = 10;

    printf("%d \n", a.x);
}