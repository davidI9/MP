#include <stdlib.h>
#include <stdio.h>
#include "Funciones.c"

int main(int argc, char* argv[]){
    
    if(argc != 2){
        printf("Error: Debes introducir un unico argumento, la ruta del archivo.\n");
        return 1;
    }

    char* path = argv[1];

    FILE* f = fopen(path, "r");
    if (f == NULL){
        printf("Error: La ruta o archivo introducida no existe.\n");
        return 1;
    }
    
    FILE* F = capFich(f, path);

    fclose(f);
    fclose(F);
    
}