#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


void ordena_parada(int array[], int menor){
    
}


int main(){

    int quantidade_carros = 0;
    int menor_numero = INT_MAX;

    scanf("%d", &quantidade_carros);
    int ordem_carros[quantidade_carros];

    for(int i=0; i<quantidade_carros; i++){
        scanf("%d", &ordem_carros[i]);
        if(menor_numero > ordem_carros[i]){
            menor_numero = ordem_carros[i];
        }
    }

    for(int i=quantidade_carros-1; i>=0; i--){
        printf("%d\n", ordem_carros[i]);
    }


    

    return 0;
}
