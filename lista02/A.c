#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int divide(int vector[], int esquerda, int direita){
    int cont;
    int auxiliar;

    cont = esquerda;

    for(int i=esquerda+1; i<=direita; i++){
        if(vector[i] < vector[esquerda]){
            cont++;
            auxiliar = vector[i];
            vector[i] = vector[cont];
            vector[cont] = auxiliar;
        }
    }

    auxiliar = vector[esquerda];
    vector[esquerda] = vector[cont];
    vector[cont] = auxiliar;

    return cont;
}


void quick_sort(int vector[], int esquerda, int direita){
    int pivo;
    if(esquerda < direita){
        pivo = divide(vector, esquerda, direita);
        quick_sort(vector, esquerda, pivo-1);
        quick_sort(vector, pivo+1, direita); 
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
    
    quick_sort(numeros, 0, quantidade_numero-1);

    for(int i=0; i<quantidade_numero; i++){
        if(i == quantidade_numero-1){
            printf("%d\n", numeros[i]);
        } else {
            printf("%d ", numeros[i]);
        }

    }


    return 0;
}

