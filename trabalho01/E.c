#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

typedef struct Semente {
    long codigo_semente;
    long nota_qualidade;
} Semente;


void merge(Semente* vector, long inicio, long meio, long fim){
    Semente *vector_temp;
    long pivo_1, pivo_2, tamanho;
    long fim1 = 0, fim2 = 0;

    tamanho = fim-inicio+1;
    
    pivo_1 = inicio;
    pivo_2 = meio+1;

    vector_temp = (Semente *) malloc (tamanho*sizeof(Semente));

    if(vector_temp != NULL){
        for(long i=0; i<tamanho; i++){
            if(!fim1 && !fim2){
                if(vector[pivo_1].nota_qualidade < vector[pivo_2].nota_qualidade){
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

        for(long j=0, k=inicio; j<tamanho; j++, k++){
            vector[k] = vector_temp[j];
        }
    }
    free(vector_temp);
}

void merge_sort(Semente* vector, long inicio, long fim){
    long meio;
    if(inicio < fim){
        meio = floor((inicio+fim)/2);
        merge_sort(vector, inicio, meio);
        merge_sort(vector, meio+1, fim);
        merge(vector, inicio, meio, fim);
    }
}



// BUSCA BINARIA
long busca_binaria(Semente* array, long tamanho, long elemento_buscado){
    long i, inicio, meio, final;
    inicio = 0;
    final = tamanho-1;
    while(inicio <= final){
        meio = (inicio + final)/2;
        if(elemento_buscado < array[meio].nota_qualidade){
            final = meio - 1;
        } else {
            if(elemento_buscado > array[meio].nota_qualidade){
                inicio = meio+1;
            } else {
                return meio;
            }
        }
    }
    return -1;
}

int main(){

    long codigo_semente;
    long melhores_sementes;
    long nota_semente; 
    long quantidade_sementes = 0;
    Semente *sementes= NULL;
    Semente *mais_sementes = NULL;

    // quantidade de sementes que serao selecionadas
    scanf("%lld", &melhores_sementes);

    // le todos os ponteiros de entrada e coloca visitado como 0;
    while(scanf("%lld %lld", &codigo_semente, &nota_semente) != EOF){
        quantidade_sementes++;
        mais_sementes = (Semente*) realloc (sementes, quantidade_sementes * sizeof(Semente));
        
        if(mais_sementes != NULL){
            sementes = mais_sementes;
            sementes[quantidade_sementes - 1].codigo_semente = codigo_semente; 
            sementes[quantidade_sementes - 1].nota_qualidade = nota_semente; 
        } else {
            free(sementes);
        }
    }

    // ordenar as sementes conforme a nota da semente, da menor para maior
    merge_sort(sementes,0, quantidade_sementes-1);

    for(long i=0; i<quantidade_sementes; i++){
        printf("%lld %lld\n", sementes[i].codigo_semente, sementes[i].nota_qualidade);
    }




    return 0;
}