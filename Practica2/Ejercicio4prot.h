#ifndef EJERCICIO4PROT_H
#define EJERCICIO4PROT_H

float* reservarMemoria(int nFil, int nCol);

void rellenaMatriz(float* matriz, int nFil, int nCol);

void imprimeMatriz(float* matriz, int nFil, int nCol);

float max(float* v, int n);

float* maxFil(float* matriz, int nFil, int nCol);

void liberarMemoria(float** matriz);

#endif