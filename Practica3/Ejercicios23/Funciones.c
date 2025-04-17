#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomFile(char* path, int nEle, int supInt, int infInt){

    srand(time(NULL));
    int ielement;
    FILE* f = fopen(path, "w");

    if(f==NULL){
        printf("Error: El archivo no se ha podido crear.\n");
        return 1;
    }

    for(int i=0; i<nEle; i++){

        ielement = ((rand()%(supInt-infInt))+infInt);
        fprintf(f, "%d ", ielement);

    }

    fclose(f);

    return 0;

}

int checkPar(int num){

    if(num%2 == 0){
        return 1;
    }
    else{
        return 0;
    }

}

float avrgPar(char* path){

    float sum=0, result;
    int aux, cont = 0;
    
    FILE* f = fopen(path, "r");
    if(f==NULL){
        printf("Error: El archivo no se ha podido encontrar/leer.\n");
        return 1;
    }

    while(fscanf(f, "%d", &aux)!=EOF){
        if(checkPar(aux)==1){
            sum+=aux;
            cont++;
        }
    }

    result = sum/cont;

    return result;

}