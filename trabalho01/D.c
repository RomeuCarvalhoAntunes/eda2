#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(){

    int quantidade_clientes = 0;
    scanf("%d", &quantidade_clientes);

    char array_clientes[quantidade_clientes][101];
    char array_clientes_unicos[quantidade_clientes][101];

    int tamanhostring;

    for(int i=0; i<quantidade_clientes; i++){
        scanf("%s", array_clientes[i]);
    }

    for(int i=0; i<quantidade_clientes; i++){
        tamanhostring = strlen(array_clientes[i]); 
        int passouMais = 0;
        int arroba = 0;
        int k=0; 
        for(int j=0; j < tamanhostring; j++){

            if(array_clientes[i][j] == '@'){
                arroba = 1;
                passouMais = 0;

            }

            if(array_clientes[i][j] == '+'){
                passouMais = 1;
            } 

            if(passouMais == 1){
                k-=1;
            }

            if(passouMais == 0){
                if((array_clientes[i][j] == '.' ) && (arroba == 0)){
                    k -= 1;
                } else {
                    array_clientes_unicos[i][k] = array_clientes[i][j];
                }
            }
            

            k++;
            
            if(j == tamanhostring-1){
                  array_clientes_unicos[i][k] = '\0';
            }
        }
    }

    int emails_unicos=1;

    for(int i=0; i<quantidade_clientes; i++){
        for(int j = i+1 ; j<quantidade_clientes; j++){
            if(strcmp(array_clientes_unicos[i],  array_clientes_unicos[j]) == 0){
                break;
            }

            if (j == quantidade_clientes-1){
                emails_unicos++;
            }
        }
    }

    printf("%d\n", emails_unicos);





    return 0;
}
