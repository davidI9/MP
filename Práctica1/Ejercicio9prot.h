//Protección contra inclusión multiple
#ifndef EJERCICIO9PROT_H
#define EJERCICIO9PROT_H

typedef struct Monomio{
    int coeficiente;
    int grado;
} Monomio;

void leerMonomio(Monomio *termino);
void imprimirMonomio(Monomio termino);
void maxmin(Monomio vector[], Monomio *gmax, Monomio *gmin, int n);
int polinomio(Monomio vector[], int X, int n);

#endif