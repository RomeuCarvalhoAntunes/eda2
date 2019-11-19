#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

typedef struct Semente {
    int codigo_semente;
    int nota_qualidade;
} Semente;


int particiona(Semente *array, int incio, int fim){
    int dir = fim;
    int esq = incio;
    Semente pivo = array[dir], aux;
    for(int i = incio; i < dir; i++){

        if(array[i].nota_qualidade <= pivo.nota_qualidade){
            
            if(array[i].nota_qualidade == pivo.nota_qualidade){
               
                if(array[i].codigo_semente < pivo.codigo_semente){
                    aux = array[i];
                    array[i] = array[esq];
                    array[esq] = aux;
                    esq++;
                }

            } else {
                aux = array[i];
                array[i] = array[esq];
                array[esq] = aux;
                esq++;
            }
        } 
    }

    aux = array[fim];
    array[fim] = array[esq];
    array[esq] = aux;

    return esq;
}

// funcao para calcular a mediana do quicksort e aumentar a velocidade
int mediana(Semente *array, int inicio, int fim){
    Semente aux;
    aux = array[(inicio+fim)/2];
    array[(inicio+fim)/2] = array[fim];
    array[fim]=aux;
    return particiona(array,inicio,fim);  
}

// quick sort que o professor utiliza chama-se ENCONTRA E COLOCA
void quick_sort(Semente *array, int inicio, int fim, int index){
    int pivo = mediana(array, inicio,fim);
    if(pivo == index){
        return;
    }
    if( pivo < index){
        // Menor que o index
        quick_sort(array,pivo+1, fim, index);
    } else {
        // Maior que o index
        quick_sort(array,inicio, pivo-1, index);
    }
}


void junta_pelo_id(Semente* vector, int inicio, int meio, int fim){
    Semente *vector_temp;
    int pivo_1, pivo_2, tamanho;
    int fim1 = 0, fim2 = 0;

    tamanho = fim-inicio+1;
    
    pivo_1 = inicio;
    pivo_2 = meio+1;

    vector_temp = (Semente *) malloc (tamanho*sizeof(Semente));

    if(vector_temp != NULL){
        for(int i=0; i<tamanho; i++){
            if(!fim1 && !fim2){
                if(vector[pivo_1].codigo_semente < vector[pivo_2].codigo_semente){
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

void ordena_pelo_id(Semente* vector, int inicio, int fim){
    int meio;
    if(inicio < fim){
        meio = floor((inicio+fim)/2);
        ordena_pelo_id(vector, inicio, meio);
        ordena_pelo_id(vector, meio+1, fim);
        junta_pelo_id(vector, inicio, meio, fim);
    }
}



int main(){

    int codigo_semente;
    int melhores_sementes;
    int nota_semente; 
    int quantidade_sementes = 0;
    Semente *sementes= NULL;
    Semente *mais_sementes = NULL;

    // quantidade de sementes que serao selecionadas
    scanf("%d", &melhores_sementes);

    // le todos os ponteiros de entrada e coloca visitado como 0;
    while(scanf("%d %d", &codigo_semente, &nota_semente) != EOF){
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

    if(quantidade_sementes <= melhores_sementes){
        quick_sort(sementes,0,quantidade_sementes-1, quantidade_sementes-1);
        ordena_pelo_id(sementes,0,quantidade_sementes-1);
        for(int i=0; i<quantidade_sementes; i++){
            printf("%d %d\n", sementes[i].codigo_semente, sementes[i].nota_qualidade);
        }
    } else {
        quick_sort(sementes,0,quantidade_sementes-1, melhores_sementes-1);
        ordena_pelo_id(sementes,0,melhores_sementes-1);
        for(int i=0; i<melhores_sementes; i++){
            printf("%d %d\n", sementes[i].codigo_semente, sementes[i].nota_qualidade);
        }

    }


    return 0;
}




