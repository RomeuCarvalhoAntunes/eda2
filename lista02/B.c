#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// TLE ;-(
// TODO
//  INSERIR OS VALORES ORDENADOS;

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
    int immprime=0;

    while(scanf("%d", &numero_teste) != EOF){
        for(int j=0; j<quantidade_numeros; j++){
            if(numero_teste == array_proibido[j]){
                printf("sim\n");
                immprime = 1;
                break;
            } else {
                immprime = 2;
            }
        
        }
        if(immprime == 2){
            printf("nao\n");

        }
    }


    return 0;
}

