#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"

int main(int argc, char** argv){

    //Comprueba que se hayan introducido suficientes argumentos por linea de comandos
    if(argc != 2){
        printf("Error: Debes introducir un unico argumento, la ruta del archivo.\n");
        return 1;
    }

    char* path = argv[1];
    int opt=0;

    while(opt!=9){
        
        displayMenu();
        scanf("%d", &opt);
        menuManagement(opt, path);
        
    }
    
    return 0;

}