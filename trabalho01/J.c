#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(){
    char palavra[6000000];
    int entradas[100001];
    int contador=0;
    int i=0;
    int inicio=0;
    int final=0;

    while(scanf("%c", &palavra[i]) != EOF){
        if(palavra[i] == '\n'){
            palavra[i] = '\0';
            final = i;
            entradas[contador] = inicio;
            inicio = final + 1;
            contador++;
        }
        i++;
    }

    int resposta=0;
    char *ultimo = &palavra[entradas[contador-1]];
    for(int i=0; i< contador - 1; i++){
        char *ponteiro_achou = strstr(&palavra[entradas[i]], ultimo);
        while(ponteiro_achou != NULL){
            resposta++;
            ponteiro_achou = strstr(ponteiro_achou + 1, ultimo);
        }
        printf("%d\n", resposta);
        resposta = 0;
    }

    return 0;
}