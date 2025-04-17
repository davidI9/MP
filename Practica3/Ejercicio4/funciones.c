#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"
#include "book.h"


/*
    Función que busca el "title" en el archivo de texto donde está el stock de libros.
    Devuelve 0 si no encuentra el libro, si lo encuentra devuelve la posición en la
    que ha encontrado el libro, empezando por el número 1.
*/
int searchByTitle(char title[30], char* path){

    FILE* stock = fopen(path, "r");
    if(stock == NULL){
        
        printf("Error: El archivo del stock no existe/no se ha podido abrir.");
        return 0;

    }


    char line[100];
    int cont=0;

    for(int i=4; (fscanf(stock, "%s", line)!=EOF); i++){

        if (i==4){
            i=0;
            cont++;

            if(strcmp(line, title)==0){
                fclose(stock);
                return cont;
            }

        }
        
    }

    fclose(stock);

    return 0;
}



/*
    Función que escribe un libro en el stock. Recibe el path del archivo, el libro que va a añadir
    y el método que va a usar para escribirlo ('a' o 'w'). No hay peligro con el argumento
    method ya que el usuario no puede acceder a la función desde el main. Devuelve 1 si falla
    la apertura del archivo y 0 se ejecuta correctamente.
    No se debe usar directamente, para añadir un nuevo libro se debe usar la función newBook.
*/
int addBook(char* path, book new, char method){

    FILE* stock = fopen(path, &method);
    if(stock == NULL){
        
        printf("Error: El archivo del stock no existe/no se ha podido abrir.");
        return 1;

    }

    fprintf(stock, "%s\n", new.title);
    fprintf(stock, "%s\n", new.author);
    fprintf(stock, "%f %d\n", new.price, new.units);

    fclose(stock);
    return 0;
}



/*
    Funcion para añadir un libro al stock. Comprueba que el nuevo libro no existe en el stock. Si la
    verificación es satisfactoria, recoge los datos del titulo y lo escribe a través de addBook().
    Devuelve 1 si el libro ya existe en el stock, 0 en caso contrario.
*/
int newBook(char* path){

    char title[30];
    printf("Introduce el titulo del libro:\n");
    scanf("%s", title);

    if(searchByTitle(title, path)>0){
        printf("Ya existe un libro con ese titulo.\n");
        return 1;
    }

    book new;
    strcpy(new.title, title);
    printf("Introduce el autor del libro:\n");
    scanf("%s", (new.author));
    printf("Introduce el precio del libro:\n");
    scanf("%f", &(new.price));
    printf("Introduce las unidades disponibles del libro:\n");
    scanf("%d", &(new.units));

    addBook(path, new, 'a');

    return 0;
}



/*
    Funcion que lee los libros del archivo del stock y los almacena en un vector.
    Recibe el path, el vector de la estructura book (libros) y el numero de instancias
    que tiene que almacenar en el vector.
*/
void readBooks(char* path, book* vector, int n){

    FILE* stock = fopen(path, "r");
    if(stock == NULL){
        
        printf("Error: El archivo del stock no existe/no se ha podido abrir.");

    } else {

        for(int i=0; i<n; i++){

            fscanf(stock, "%s", vector[i].title);
            fscanf(stock, "%s", vector[i].author);
            fscanf(stock, "%f", &(vector[i].price));
            fscanf(stock, "%d", &(vector[i].units));

        }

    }  
    
    fclose(stock);

}



/* 
    Función que cuenta el numero de titulos diferentes que hay. Recibe el path y devuelve
    el numero de titulos diferentes. Devuelve -1 en caso de error.
*/
int titlesNumber(char* path){

    char line[100];

    FILE* stock = fopen(path, "r");
    if(stock == NULL){
        
        printf("Error: El archivo del stock no existe/no se ha podido abrir.");
        return -1;

    }

    int cont=0;
    for(int i=4; fscanf(stock, "%s", line)!=EOF; i++){

        if(i==4){
            cont++;
            i=0;
        }

    }

    fclose(stock);

    return cont;

}



/*
    Función que imprime por pantalla todos los libros con sus respectivos datos.
    Recibe el path, devuelve 1 en caso de error y 0 si funciona correctamente.
*/
int listBooks(char* path){

    char line[100];

    FILE* stock = fopen(path, "r");
    if(stock == NULL){
        
        printf("Error: El archivo del stock no existe/no se ha podido abrir.");
        return 1;

    }

    for(int i=0; fscanf(stock, "%s", line)!=EOF; i++){

        switch (i){

            case 0:
                printf("Titulo: %s\n", line); 
                break;
            case 1:
                printf("Autor: %s\n", line); 
                break;
            case 2:
                printf("Precio: %s\n", line); 
                break;
            case 3:
                printf("Unidades disponibles: %s\n", line);
                i = -1;
                break;
        
            default:
                break;
        }

    }

    fclose(stock);

    return 0;

}



/*
    Función que crea un vector dinámico de libros que rellena con los libros almacenados
    en el stock. Recibe el path del archivo del stock y el tamaño del vector, y devuelve
    el vector dinámico rellenado.
*/
book* createArray(char* path, int n){

    book* vector = (book*)calloc(n, sizeof(book));
    
    readBooks(path, vector, n);

    return vector;
}

/*
    Función que escribe el vector en el archivo de texto especificado. Recive el path del
    archivo de texto a escribir, el vector de libros y el tamaño de dicho vector (cantidad de
    libros a escribir).
*/
void writeVector(char* path, book* vector, int n){

    if(n>0){

        addBook(path, *vector, 'w');

        for(int i=1; i<n; i++){
            addBook(path, vector[i], 'a');
        }
    
    }

}



/*
    Función que sirve para subir el precio, en un porcentaje, de todos los libros del stock.
    Utiliza un vector intermedio para esto. Recuibe la ruta del archivo del stock, el porcentaje
    a subir y el número de libros que tiene el archivo (para poder rellenar el vector).
*/
void raisePrices(char* path, float percentage, int n){

    book* vector = createArray(path, n);

    for(int i=0; i<n; i++){
        vector[i].price = vector[i].price + vector[i].price*percentage;
    }

    writeVector(path, vector, n);

    free(vector);

}



/*
    Función que sirve para vender la cantidad de unidades de un título especificada por el usuario.
    Recibe el path al archivo del stock. Si la cantidad de unidades vendidas supera las existencias
    en el stock, vende las suficientes para quedarse a 0.
*/
void unitsSeller(char* path){

    char title[50];
    int u=0, index, n;

    printf("¿De que titulo quieres vender unidades?\n");
    scanf("%s", title);

    if((index = searchByTitle(title, path))>0){

        printf("¿Cuantos libros quieres vender?\n");
        scanf("%d", &u);

        book* vector = createArray(path, n = titlesNumber(path));
        vector[index-1].units -= u;

        if(vector[index-1].units < 0){
            printf("No hay suficientes existencias para afrontar la demanda, se han vendido %d unidades\n", u+vector[index-1].units);
            vector[index-1].units=0;
        }

        writeVector(path, vector, n);

        free(vector);

    } else{

        printf("El libro no se encuentra en el stock.\n");

    }

}



/*
    Función que genera un fichero de texto con los titulos con menos de x unidades.
    Recibe el path al stock de libros y la cantidad maxima de unidades.
*/
void generateFich(char* path, int maxUnits){

    int n = titlesNumber(path), j=0;
    book* vector = createArray(path, n);
    book* vector2 = (book*)calloc(n, sizeof(book));

    for(int i=0; i<n; i++){

        if(vector[i].units < maxUnits){
            vector2[j] = vector[i];
            j++;
        }

    }

    writeVector("belowUnitsFich.txt", vector2, j);

    free(vector);
    free(vector2);

}



/*
    Función que elimina aquellos libros que no tengan existencias, crea un archivo 
    temporal a traves de la función generateFich que almacena los libros con más de 
    0 unidades y cuando lo hace con todos elimina el orignal y renombra el temporal.
*/
void delete0Titles(char* path){

    char line[100];

    FILE* stock = fopen(path, "r");
    if(stock == NULL){
        
        printf("Error: El archivo del stock no existe/no se ha podido abrir.");

    }else{

        book current;

        for(int i=4; fscanf(stock, "%s", line)!=EOF; i++){
    
            switch (i){
    
                case 1:
    
                    strcpy(current.author, line); 
                    break;
    
                case 2:
    
                    current.price = strtof(line, NULL);
                    break;
    
                case 3:
    
                    current.units = atoi(line);
                    if(strcmp(line, "0")!=0){
                        addBook("temp.txt", current, 'a');
                    }
                    break;
                
                case 4:
    
                    strcpy(current.title, line);
                    i=0;
                    break;
            
                default:
                    break;
            }
    
        }
       
    }
 
    fclose(stock);

    remove(path);
    rename("temp.txt", path);

}