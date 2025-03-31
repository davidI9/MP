#include <stdio.h>
#include <stdlib.h>
#include "Ejercicio5funct.c"
#include <string.h>

int main(){

    int n;
    printf("Introduce la cantidad de jugadores que quieres registrar en el equipo:\n");
    scanf("%d", &n);

    Jugador* equipo = reservarMemoria(n);

    rellenarEquipo(equipo, n);

    imprimirEquipo(equipo, n);

    n = borrarJugador(equipo, n, 'a');

    imprimirEquipo(equipo, n);

    free(equipo);

}