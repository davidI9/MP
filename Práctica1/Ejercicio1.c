#include <stdlib.h>
#include <stdio.h>

int main(){
    int a, *b, *c;
    double d, *e, **f;
    char g, *h, **i;

    //está bien pero tira warnings por algun motivo, pero si, se supone que hace eso.

    printf("Tamaño de a es: %d", sizeof(a));
    printf("Tamaño de b es: %d", sizeof(b));
    printf("Tamaño de c es: %d", sizeof(c));
    printf("Tamaño de d es: %d", sizeof(d));
    printf("Tamaño de e es: %d", sizeof(e));
    printf("Tamaño de f es: %d", sizeof(f));
    printf("Tamaño de g es: %d", sizeof(g));
    printf("Tamaño de h es: %d", sizeof(h));
    printf("Tamaño de i es: %d", sizeof(i));
}
