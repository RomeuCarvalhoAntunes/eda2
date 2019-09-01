#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(){

    char cidade[26];
    int numero_cidades = 0;
    char **cidades= NULL;
    char **mais_cidades = NULL;
    int retorno_scanf;
    char **cidades_atualizadas = 0;

    do{
        retorno_scanf = scanf("%s", &cidade);
        numero_cidades++;
        mais_cidades = realloc (cidades, numero_cidades * sizeof(cidade));
        if(mais_cidades != NULL){
            cidades = mais_cidades;
            char* cidade_atual = (char*) malloc(sizeof(char) * 26);
            strcpy(cidade_atual, cidade);
            cidades[numero_cidades - 1] = cidade_atual; 
        } else {
            free(cidades);
        }
    }while(retorno_scanf != EOF);

    // ultimo caracter ta na ultima posicao =-1 
    char ultimo_caracter = 0;
    char *cidade_temp=NULL;
    int tamanho_string = 0;

    for(int i=0; i<numero_cidades-1; i++){
        // tamanho_string = strlen(cidades[0]);
        printf("%s\n",  cidades[0]);
        // ultimo_caracter = cidades[i][tamanho_string-1];
        // printf("%s\n", ultimo_caracter);
        // if(cidades[i+1][0] == ultimo_caracter && i != 0){
        //     cidade_temp = cidades[i];
        //     cidades[i] = cidades[i+1];
        //     cidades[i+1] = cidade_temp;
        // }
    }
    
    // for(int i=0; i<numero_cidades-1; i++){
    //     printf("%s\n", cidades[i]);
    // }

    

    return 0;
}
