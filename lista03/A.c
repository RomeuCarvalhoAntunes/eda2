#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

void merge(int vector[], int inicio, int meio, int fim){
    int *vector_temp, pivo_1, pivo_2, tamanho;
    int fim1 = 0, fim2 = 0;

    tamanho = fim-inicio+1;
    
    pivo_1 = inicio;
    pivo_2 = meio+1;

    vector_temp = (int *) malloc (tamanho*sizeof(int));

    if(vector_temp != NULL){
        for(int i=0; i<tamanho; i++){
            if(!fim1 && !fim2){
                if(vector[pivo_1] < vector[pivo_2]){
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

        for(int j=0, k=inicio; j<tamanho; j++, k++){
            vector[k] = vector_temp[j];
        }
    }
    free(vector_temp);
}

void merge_sort(int vector[], int inicio, int fim){
    int meio;
    if(inicio < fim){
        meio = floor((inicio+fim)/2);
        merge_sort(vector, inicio, meio);
        merge_sort(vector, meio+1, fim);
        merge(vector, inicio, meio, fim);
    }
}

int main(){

    int entrada_numero;
    int quantidade_numero = 0;
    int *numeros= NULL;
    int *mais_numeros = NULL;

    while( scanf("%d", &entrada_numero) != EOF){
        quantidade_numero++;
        mais_numeros = (int*) realloc (numeros, quantidade_numero * sizeof(int));
        
        if(mais_numeros != NULL){
            numeros = mais_numeros;
            numeros[quantidade_numero - 1] = entrada_numero; 
        } else {
            free(numeros);
        }
    }
    
    merge_sort(numeros, 0, quantidade_numero-1);

    for(int i=0; i<quantidade_numero; i++){
        if(i == quantidade_numero-1){
            printf("%d\n", numeros[i]);
        } else {
            printf("%d ", numeros[i]);
        }

    }
    return 0;
}

