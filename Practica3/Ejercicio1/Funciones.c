#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"
#include <ctype.h>

FILE* capFich(FILE* originalf, char* path){

    char prefix[FILENAME_MAX] = "caps_";
    path = strcat(prefix, path);

    FILE* cappedFich = fopen(path, "w");
    if(cappedFich==NULL){
        printf("Error: No se ha podido llevar acabo la creación del nuevo archivo.\n");
        return NULL;
    }

    char line[100];
    while(fgets(line, 100, originalf) != NULL){

        for(int i=0; (line[i]!='\n')&&(i<100); i++){
            line[i] = toupper((unsigned char) line[i]);
        }

        fputs(line, cappedFich);

    }

    return cappedFich;

}