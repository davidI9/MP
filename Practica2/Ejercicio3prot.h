#ifndef EJERCICIO3PROT_H
#define EJERCICIO3PROT_H

int** reservarMemoria(int nFil, int nCol);

void rellenaMatriz(int** matriz, int nFil, int nCol);

void imprimeMatriz(int** matriz, int nFil, int nCol);

int min(int* v, int n);

int* minCol(int** matriz, int nFil, int nCol);

void liberarMemoria(int*** matriz, int nFil);

#endif