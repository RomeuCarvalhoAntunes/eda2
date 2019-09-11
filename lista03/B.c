#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

void merge(int vector[], int inicio, int meio, int fim){
    int *vector_temp, pivo_1, pivo_2, tamanho;
    int fim1 = 0, fim2 = 0;

    tamanho = fim-inicio+1;
    
    pivo_1 = inicio;
    pivo_2 = meio+1;

    vector_temp = (int *) malloc (tamanho*sizeof(int));

    if(vector_temp != NULL){
        for(int i=0; i<tamanho; i++){
            if(!fim1 && !fim2){
                if(vector[pivo_1] < vector[pivo_2]){
                    vector_temp[i] = vector[pivo_1++];
                } else {
                    vector_temp[i] = vector[pivo_2++];
                }
                if(pivo_1>meio) fim1 = 1;
                if(pivo_2>fim) fim2 = 1;
            } else {
                if(!fim1){
                    vector_temp[i] = vector[pivo_1++];
                } else {
                    vector_temp[i] = vector[pivo_2++];                    
                }
            }
        }

        for(int j=0, k=inicio; j<tamanho; j++, k++){
            vector[k] = vector_temp[j];
        }
    }
    free(vector_temp);
}

void merge_sort(int vector[], int inicio, int fim){
    int meio;
    if(inicio < fim){
        meio = floor((inicio+fim)/2);
        merge_sort(vector, inicio, meio);
        merge_sort(vector, meio+1, fim);
        merge(vector, inicio, meio, fim);
    }
}



int main(){

    int quantidade_patos;


    while (scanf("%d", &quantidade_patos) != 0){
        
        if(quantidade_patos == 0){
            break;
        }

        int mechas_patos[quantidade_patos];

        for(int i=0; i<quantidade_patos; i++){
            scanf("%d", &mechas_patos[i]);
        }

        merge_sort(mechas_patos,0,quantidade_patos-1);


//        int quantidade_repetida=0;
//        int majoritario=0;
        int codigo_majoritario=0;
//        int codigo_cor_atual;
        int meio = floor((quantidade_patos/2));
        codigo_majoritario = mechas_patos[meio]; 
//        for(int i=0; i<quantidade_patos; i++){
//            codigo_cor_atual = mechas_patos[i];
//            quantidade_repetida = 0;
//            for(int i=0; i<quantidade_patos; i++){
//                if(mechas_patos[i]== codigo_cor_atual){
//                    quantidade_repetida++;
//                    if(quantidade_repetida > majoritario){
//                        majoritario = quantidade_repetida;
//                        codigo_majoritario = codigo_cor_atual;
//                    }
//                }
//            }
//        }
            printf("%d\n", codigo_majoritario);
    }

    return 0;
}

