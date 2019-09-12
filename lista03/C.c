#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

void merge(int* vector, int inicio, int meio, int fim){
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

void merge_sort(int* vector, int inicio, int fim){
    int meio;
    if(inicio < fim){
        meio = floor((inicio+fim)/2);
        merge_sort(vector, inicio, meio);
        merge_sort(vector, meio+1, fim);
        merge(vector, inicio, meio, fim);
    }
}



int main(){

    int numero_senadores_eleitos;
    int numero_dp_federais_eleitos;
    int numero_dp_estaduais_eleitos;

    int *votos_presidente = NULL;
    int *mais_votos_presidente = NULL;
    int quantidade_votos_presidente = 0; 
    int quantida_votos_invalidos_presidente = 0;

    int *votos_senadores = NULL;
    int *mais_votos_senadores = NULL;
    int quantidade_votos_senadores = 0;

    int *votos_dp_federais = NULL;
    int *mais_votos_dp_federais = NULL;
    int quantidade_votos_deputados_federais = 0;

    int *votos_dp_estaduais = NULL;
    int *mais_votos_dp_estaduais = NULL;
    int quantidade_votos_deputados_estaduais = 0;


    int votos_validos = 0;
    int votos_brancos_nulos = 0;

    scanf("%d", &numero_senadores_eleitos);
    scanf("%d", &numero_dp_federais_eleitos);
    scanf("%d", &numero_dp_estaduais_eleitos);

    int voto_eleitor;

    while(scanf("%d", &voto_eleitor) != EOF){
        if(voto_eleitor < 0){
            votos_brancos_nulos++;
            if(voto_eleitor >= -99 && voto_eleitor <= -1){
                quantida_votos_invalidos_presidente++;
            }

        } else {
            votos_validos++;

            if(voto_eleitor >= 0 && voto_eleitor <= 99){
                // voto presidente;
                quantidade_votos_presidente++;
                mais_votos_presidente = (int*) realloc (votos_presidente, quantidade_votos_presidente * sizeof(int));

                if(mais_votos_presidente != NULL){
                    votos_presidente = mais_votos_presidente;
                    votos_presidente[quantidade_votos_presidente -1] = voto_eleitor;
                } else {
                    free(votos_presidente);
                }
            }

            else if(voto_eleitor >= 100 && voto_eleitor <= 999){
                //voto senador;
                quantidade_votos_senadores++;
                mais_votos_senadores = (int*) realloc (votos_senadores, quantidade_votos_senadores * sizeof(int));

                if(mais_votos_senadores != NULL){
                    votos_senadores = mais_votos_senadores;
                    votos_senadores[quantidade_votos_senadores -1] = voto_eleitor;
                } else {
                    free(votos_senadores);
                }
            }

            else if(voto_eleitor >= 1000 && voto_eleitor <= 9999){
                // voto deputado federal;
                quantidade_votos_deputados_federais++;
                mais_votos_dp_federais = (int*) realloc (votos_dp_federais, quantidade_votos_deputados_federais * sizeof(int));

                if(mais_votos_dp_federais != NULL){
                    votos_dp_federais = mais_votos_dp_federais;
                    votos_dp_federais[quantidade_votos_deputados_federais -1] = voto_eleitor;
                } else {
                    free(votos_dp_federais);
                }
            }

            else {
                // voto deputado estadual
                quantidade_votos_deputados_estaduais++;
                mais_votos_dp_estaduais = (int*) realloc (votos_dp_estaduais, quantidade_votos_deputados_estaduais * sizeof(int));

                if(mais_votos_dp_estaduais != NULL){
                    votos_dp_estaduais = mais_votos_dp_estaduais;
                    votos_dp_estaduais[quantidade_votos_deputados_estaduais -1] = voto_eleitor;
                } else {
                    free(votos_dp_estaduais);
                }
            }
        }
    }

    merge_sort(votos_presidente, 0, quantidade_votos_presidente-1);
    merge_sort(votos_senadores, 0, quantidade_votos_senadores-1);
    merge_sort(votos_dp_federais, 0, quantidade_votos_deputados_federais-1);
    merge_sort(votos_dp_estaduais, 0, quantidade_votos_deputados_estaduais-1);
    

    printf("VALIDOS:%d    NULOS:%d\n", votos_validos, votos_brancos_nulos);

    printf("%d", quantida_votos_invalidos_presidente);

    if(quantidade_votos_presidente >= ceil((quantida_votos_invalidos_presidente)*0.51)){
        // existem 51% de votos validos para o presidente;
    } else {
        printf("Segundo Turno\n");
    }

    for(int i=0; i<quantidade_votos_presidente; i++){
   //     printf("%d, ", votos_presidente[i]);
    }

    printf("\n");

    for(int i=0; i<quantidade_votos_senadores; i++){
     //   printf("%d, ", votos_senadores[i]);
    }

    printf("\n");

    for(int i=0; i<quantidade_votos_deputados_federais; i++){
       // printf("%d, ", votos_dp_federais[i]);
    }

    printf("\n");

    for(int i=0; i<quantidade_votos_deputados_estaduais; i++){
     //   printf("%d, ", votos_dp_estaduais[i]);
    }

    printf("\n");



    

    
    

    return 0;
}

