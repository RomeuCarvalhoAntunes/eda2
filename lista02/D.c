#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

typedef struct Casa {
    int numero_casa;
    int indice_casa;
} Casa;

int busca_binaria(struct Casa casas[], int tamanho, int elemento_buscado){
    int i, inicio, meio, final;
    inicio = 0;
    final = tamanho-1;

    while(inicio <= final){
        meio = (inicio + final)/2;
        if(elemento_buscado < casas[meio].numero_casa){
            final = meio - 1;
        } else {
            if(elemento_buscado > casas[meio].numero_casa){
                inicio = meio+1;
            } else {
                return casas[meio].indice_casa;
            }
        }
    }

    return -1;
}

int main(){

    int quantidade_casas;
    int quantidade_encomendas;
    
    scanf("%d %d", &quantidade_casas, &quantidade_encomendas);
    
    Casa casas[quantidade_casas];


    int local_encomendas[quantidade_encomendas];
    int numero_casa;
    int indice_casa=0;

    for(int i=0; i<quantidade_casas; i++){
        scanf("%d", &numero_casa);
        casas[i].numero_casa = numero_casa;
        casas[i].indice_casa = indice_casa;
        indice_casa++; 
    }

    for(int i=0; i<quantidade_encomendas; i++){
        scanf("%d", &local_encomendas[i]);
    }

    int indice_casa_inicial =0;
    int indice_proxima_casa=0;
    int tempo =0;

    for(int i=0; i<quantidade_encomendas; i++){
        indice_proxima_casa = busca_binaria(casas,quantidade_casas,local_encomendas[i]);
        tempo = tempo + (abs(indice_proxima_casa - indice_casa_inicial ));
        indice_casa_inicial = indice_proxima_casa;
    }

    printf("%d\n", tempo);

    return 0;
}

