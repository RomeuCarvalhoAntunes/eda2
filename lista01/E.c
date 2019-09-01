#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(){

    int entrada_numero;
    int quantidade_numero = 0;
    int minimo;
    int *numeros= NULL;
    int *mais_numeros = NULL;

    do {
        scanf("%d", &entrada_numero);
        quantidade_numero++;
        mais_numeros = (int*) realloc (numeros, quantidade_numero * sizeof(int));
        
        if(mais_numeros != NULL){
            numeros = mais_numeros;
            numeros[quantidade_numero - 1] = entrada_numero; 
        } else {
            free(numeros);
        }

    }while (entrada_numero != 0);

    scanf("%d", &minimo);

    int soma = 0;
    int array_ultrapassou[quantidade_numero];
    int tamanho=0;

    for(int i=0; i<quantidade_numero; i++){
         soma+= numeros[i];
        if(soma > minimo){
            array_ultrapassou[tamanho] = numeros[i];
            tamanho++;
            soma = 0;
        }
    }

    for(int j=tamanho-1; j>=0; j--){
        printf("%d\n", array_ultrapassou[j]);
    }

    

    return 0;
}
