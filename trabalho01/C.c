#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

typedef struct Bairro {
    int *valores;
    int eu_vou_estar;
    int numero_vizinhos;
} Bairro;




int main(){

    int qnt_locais_bairro;
    int locais_juliano_visto;
    int locais_juliano_saber;


    scanf("%d %d %d", &qnt_locais_bairro, &locais_juliano_visto, &locais_juliano_saber);


    Bairro *bairro;
    bairro = (Bairro*)malloc(sizeof(Bairro)* qnt_locais_bairro);

    for(int i=0; i<qnt_locais_bairro; i++){
        int vizinhos;
        scanf("%d", &vizinhos);
        bairro[i].numero_vizinhos = vizinhos;
        bairro[i].valores = (int*)malloc(sizeof(int)*vizinhos);

        for(int j=0; j<vizinhos; j++){
            int temp;
            scanf("%d", &temp);
            if(temp == 0){
                temp = -1;
            }
            bairro[i].valores[j] = temp;
        }
    }

    // bairro eu vou estar la -1 juliano estará
    for(int i=0; i<locais_juliano_visto; i++){

        int temp;
        scanf("%d", &temp);
        bairro[temp].eu_vou_estar = -1;

        for(int j=0; j<bairro[temp].numero_vizinhos; j++){
            int temp2;
            temp2 = bairro[temp].valores[j];
            if(temp2 != 0){
                if(temp2 == -1){
                    temp2 = 0;
                }
                bairro[temp2].eu_vou_estar = -1;
            }
        }
    }

    while (locais_juliano_saber--){
        int juliano_esta;
        scanf("%d", &juliano_esta);
        if(bairro[juliano_esta].eu_vou_estar == -1){
            printf("Eu vou estar la\n");
        } else{
            printf("Nao vou estar la\n");
        }
    }

    return 0;
}
