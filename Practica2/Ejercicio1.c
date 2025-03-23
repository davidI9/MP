#include <stdio.h>
#include <stdlib.h>

int main(){
    double** tabla[2][3];
    printf("%p\n", tabla);                  //imprime el espacio de memoria de la primera "fila"
    printf("%p\n", tabla+1);                //imprime el espacio de memoria de la segunda "fila"
    printf("%p\n", *(tabla+1));             //imprime el espacio de memoria de la primera "columna" de la segunda "fila"
    printf("%p\n", (*(tabla+1)+1));         //imprime el espacio de memoria de la segunda "columna" de la segunda "fila"
    printf("%p\n", (*(tabla)+1));           //imprime el espacio de memoria de la segunda "columna" de la primera "fila"
    printf("%p\n", *(*(tabla+1)+1));        //imprime el elemento de la segunda "columna" de la segunda "fila"
    printf("%p\n", *(*(tabla)+1));          //imprime el elemento de la segunda "columna" de la primera "fila"
    printf("%p\n", *(*(tabla+1)));          //imprime el elemento de la primera "columna" de la segunda "fila"
}