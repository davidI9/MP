#include "Funciones.c"
#include <stdlib.h>

int main(){

    char path[FILENAME_MAX];
    int supInt, infInt, nEle;

    printf("Introduce el nombre del archivo que quieras crear o la ruta donde quieras crearlo:\n");
    scanf("%s", path);

    printf("Introduce el intervalo inferior:\n");
    scanf("%d", &infInt);

    printf("Introduce el intervalo superior:\n");
    scanf("%d", &supInt);

    printf("Introduce el numero de elementos:\n");
    scanf("%d", &nEle);

    randomFile(path, nEle, supInt, infInt);

}