#ifndef EJERCICIO12PROT_H
#define EJERCICIO12PROT_H

typedef struct Fraccion{
    int numerador;
    int denominador;
} Fraccion;
void rfra(Fraccion* variable);
void imfra(Fraccion* variable);
void multfra(Fraccion* res, Fraccion* var1, Fraccion* var2);

#endif