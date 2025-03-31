#ifndef EJERCICIO5PROT_H
#define EJERCICIO5PROT_H

typedef struct Jugador{

    char nombre[50];
    int dorsal;
    float peso;
    int estatura;

} Jugador;

Jugador* reservarMemoria(int n);

void crearJugador(Jugador* jugador);

void rellenarEquipo(Jugador* equipo, int n);

void imprimirEquipo(Jugador* equipo, int n);

int borrarJugador(Jugador* equipo, int n, char filtro);

#endif