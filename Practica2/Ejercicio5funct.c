#include <stdio.h>
#include <stdlib.h>
#include "Ejercicio5prot.h"
#include <string.h>
#include <ctype.h>


Jugador* reservarMemoria(int n){

    Jugador* equipo = (Jugador*)calloc(n, sizeof(Jugador));

    return equipo;

}

void crearJugador(Jugador* jugador){

    printf("Introduce el nombre del jugador: \n");
    scanf("%49s", (jugador->nombre));

    printf("Introduce el dorsal del jugador: \n");
    scanf("%d", &(jugador->dorsal));

    printf("Introduce la altura del jugador en cm: \n");
    scanf("%d", &(jugador->estatura));

    printf("Introduce el peso del jugador en kg: \n");
    scanf("%f", &(jugador->peso));

}

void rellenarEquipo(Jugador* equipo, int n){

    for(int i=0; i<n; i++){

        crearJugador(&equipo[i]);

    }

}

void imprimirEquipo(Jugador* equipo, int n){

    for(int i=0; i<n; i++){

        printf("0%d %s\n", i, (equipo[i].nombre));

    }

}

int borrarJugador(Jugador* equipo, int n, char filtro){

    for(int i=0; i<n; i++){

        for(int j=0; j<strlen(equipo[i].nombre); j++){

            if(tolower(equipo[i].nombre[j]) == tolower(filtro)){

                equipo[i] = equipo[n-1];
                n--;
                equipo = (Jugador*)realloc(equipo, n * sizeof(Jugador));
                i--;
                j=0;

            }

        }

    }

    return n;

}
