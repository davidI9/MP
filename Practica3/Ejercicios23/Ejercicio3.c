#include "Funciones.c"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]){

    if(argc != 2){
        printf("Error: Debes introducir un unico argumento, la ruta del archivo.\n");
        return 1;
    }

    char* path = argv[1];

    float average = avrgPar(path);
    printf("La media de los numero pares del archivo es: %f\n", average);

    return 0;

}