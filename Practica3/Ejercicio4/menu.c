#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "funciones.h"

//funcion para printear el menu
void displayMenu(){

    printf("Escoge una de las siguientes opciones.\n");
    printf("1. Buscar por título.\n");
    printf("2. Introducir un nuevo libro.\n");
    printf("3. Ver cantidad de libros.\n");
    printf("4. Listar todos los libros.\n");
    printf("5. Incrementar el precio de todos los libros.\n");
    printf("6. Vender n unidades.\n");
    printf("7. Generar fichero de los libros de los que se dispongan menos de x unidades.\n");
    printf("8. Borrar titulos sin existencias.\n");
    printf("9. Salir.\n");

}

//funcion para gestionar el menu en funcion de la opcion escogida por el usuario
void menuManagement(int opt, char* path){

    switch(opt){
        case 1:

            //Buscar por el titulo
            char title[30];
            printf("Introduce el titulo del libro:\n");
            scanf("%s", title);

            if(searchByTitle(title, path)>0){
                printf("El libro se encuentra en el stock.\n");
            } else {
                printf("El libro no se encuentra en el stock.\n");
            }

            break;

        case 2:

            //añadir un nuevo libro
            newBook(path);

            break;

        case 3:

            //contar numero de titulos diferentes:
            printf("Hay %d titulos diferentes.\n", titlesNumber(path));

            break;

        case 4:

            //listar todos los libros disponibles
            listBooks(path);

            break;

        case 5:

            float percentage;
            printf("¿En que porcentaje quieres aumentar el precio de los libros? (0 a 1):\n");
            scanf("%f", &percentage);
            int n = titlesNumber(path);
            raisePrices(path, percentage, n);
            
            break;

        case 6:

            unitsSeller(path);

            break;

        case 7:

            int maxUnits=0;
            printf("¿Cual es el maximo de unidades?\n");
            scanf("%d", &maxUnits);
            generateFich(path, maxUnits);

            break;

        case 8:

            delete0Titles(path);
            break;

        case 9:

            break;
    
        default:
            break;
    }
}