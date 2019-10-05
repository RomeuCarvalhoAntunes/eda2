#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

typedef struct Sementes {
    long int codigo_semente;
    long int nota_semente;
} Sementes;


void merge(Sementes *vector, long int inicio, long int meio, long int fim){
    Sementes *vector_temp; 
    long int pivo_1, pivo_2, tamanho;
    long int fim1 = 0, fim2 = 0;

    tamanho = fim-inicio+1;
    
    pivo_1 = inicio;
    pivo_2 = meio+1;

    vector_temp = (Sementes *) malloc (tamanho*sizeof(Sementes));

    if(vector_temp != NULL){
        for(long long int i=0; i<tamanho; i++){
            if(!fim1 && !fim2){
                if(vector[pivo_1].nota_semente < vector[pivo_2].nota_semente){
                    vector_temp[i] = vector[pivo_1++];
                } else {
                    vector_temp[i] = vector[pivo_2++];
                }
                if(pivo_1>meio) fim1 = 1;
                if(pivo_2>fim) fim2 = 1;
            } else {
                if(!fim1){
                    vector_temp[i] = vector[pivo_1++];
                } else {
                    vector_temp[i] = vector[pivo_2++];                    
                }
            }
        }

        for(long int j=0, k=inicio; j<tamanho; j++, k++){
            vector[k] = vector_temp[j];
        }
    }
    free(vector_temp);
}

void merge_sort(Sementes *vector, long int inicio, long int fim){
    int meio;
    if(inicio < fim){
        meio = floor((inicio+fim)/2);
        merge_sort(vector, inicio, meio);
        merge_sort(vector, meio+1, fim);
        merge(vector, inicio, meio, fim);
    }
}

int main(){

    long int codigo_semente;
    long int nota_semente;
    long int melhores_sementes;
    long quantidade_numero = 0;
    Sementes *sementes= NULL;
    Sementes *mais_sementes = NULL;

    scanf("%d", &melhores_sementes);

    while(1){

        scanf("%d", &codigo_semente);
        
        if(codigo_semente == EOF){
            break;
        }
        
        scanf("%d", &nota_semente);
        
        if(nota_semente == EOF){
             break;
        } else {
            quantidade_numero++;
            mais_sementes = (Sementes*) realloc (sementes, quantidade_numero * sizeof(Sementes));
            
            if(mais_sementes != NULL){
                sementes = mais_sementes;
                sementes[quantidade_numero - 1].codigo_semente = codigo_semente ; 
                sementes[quantidade_numero - 1].nota_semente = nota_semente ; 
            } else {
                free(sementes);
            }
        }
    }

    merge_sort(sementes, 0, quantidade_numero-1);

    for(int i=0; i<melhores_sementes; i++){
     printf("%d %d\n", sementes[i].codigo_semente, sementes[i].nota_semente);
    }
    
    return 0;
}

