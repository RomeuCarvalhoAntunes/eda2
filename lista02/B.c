#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// TLE ;-(
// TODO
//  INSERIR OS VALORES ORDENADOS;

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

    int quantidade_numeros=0;

    scanf("%d", &quantidade_numeros);

    int array_proibido[quantidade_numeros];
    int numero_proibido;

    for(int i=0; i<quantidade_numeros; i++){
        scanf("%d", &numero_proibido);
        array_proibido[i] = numero_proibido;
    } 

    int numero_teste;
    int imprime = 0;

    quick_sort(array_proibido, 0, quantidade_numeros-1);   

    while(scanf("%d", &numero_teste) != EOF){
        for(int j=0; j<quantidade_numeros; j++){
            if( numero_teste == array_proibido[j]){
                printf("sim\n");
                imprime = 1;
                break;
            } 

            else if((array_proibido[j] != array_proibido[j+1]) && array_proibido[j+1] < numero_teste){
                imprime = 2;
                break;
            }

            else{
                imprime =2;
            }
           
        }

        if(imprime == 2){
            printf("nao\n");
        }
        
    }
        
    return 0;
}

