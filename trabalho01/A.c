#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

typedef struct Node {
    unsigned long endereco_no;
    unsigned long endereco_anterior;
    unsigned long endereco_prox;
    long visitado;
} Node;

// create merge sort here
void merge(Node* vector, long inicio, long meio, long fim){
    Node *vector_temp;
    long pivo_1, pivo_2, tamanho;
    long fim1 = 0, fim2 = 0;

    tamanho = fim-inicio+1;
    
    pivo_1 = inicio;
    pivo_2 = meio+1;

    vector_temp = (Node *) malloc (tamanho*sizeof(Node));

    if(vector_temp != NULL){
        for(long i=0; i<tamanho; i++){
            if(!fim1 && !fim2){
                if(vector[pivo_1].endereco_no < vector[pivo_2].endereco_no){
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
void merge_sort(Node* vector, long inicio, long fim){
    long meio;
    if(inicio < fim){
        meio = floor((inicio+fim)/2);
        merge_sort(vector, inicio, meio);
        merge_sort(vector, meio+1, fim);
        merge(vector, inicio, meio, fim);
    }
}

// BUSCA BINARIA
long busca_binaria(Node* array, long tamanho, long elemento_buscado){
    long i, inicio, meio, final;
    inicio = 0;
    final = tamanho-1;
    while(inicio <= final){
        meio = (inicio + final)/2;
        if(elemento_buscado < array[meio].endereco_no){
            final = meio - 1;
        } else {
            if(elemento_buscado > array[meio].endereco_no){
                inicio = meio+1;
            } else {
                return meio;
            }
        }
    }
    return -1;
}

int main(){

    unsigned long endereco;
    unsigned long anterior;
    unsigned long proximo; 
    long quantidade_nos = 0;
    Node *nodes= NULL;
    Node *more_nodes = NULL;

    // le todos os ponteiros de entrada e coloca visitado como 0;
    while(scanf("%lx %lx %lx", &endereco, &anterior, &proximo) != EOF){
        quantidade_nos++;
        more_nodes = (Node*) realloc (nodes, quantidade_nos * sizeof(Node));
        
        if(more_nodes != NULL){
            nodes = more_nodes;
            nodes[quantidade_nos - 1].endereco_no = endereco; 
            nodes[quantidade_nos - 1].endereco_anterior = anterior; 
            nodes[quantidade_nos - 1].endereco_prox = proximo; 
            nodes[quantidade_nos - 1].visitado = 0;
        } else {
            free(nodes);
        }
    }

    // seta ptr1 e ptr2;
    Node no_ptr1 = nodes[0];
    Node no_ptr2 = nodes[1];
    Node aux_ptr1 = no_ptr1;
    Node aux_ptr2 = no_ptr2;

    // Ordena a entrada com base no endereco do ponteiro.
    merge_sort(nodes,0,quantidade_nos-1);

    // variaveis auxiliares para criacao do caminho de ida
    long caminho_ida[quantidade_nos];
    long tamanho_caminho_ida = 0;
    long index_ida_prox = 0;
    long index_ida_visitado = 0;

    // constroi caminho de ida
    while(no_ptr1.endereco_no != no_ptr2.endereco_no){
        caminho_ida[tamanho_caminho_ida] = no_ptr1.endereco_no;
        tamanho_caminho_ida++;

        // busca para marcar que visitei o no
        index_ida_visitado = busca_binaria(nodes, quantidade_nos, no_ptr1.endereco_no);
        nodes[index_ida_visitado].visitado = 1;

        // busca para verificar se o no prox existe
        index_ida_prox = busca_binaria(nodes,quantidade_nos,no_ptr1.endereco_prox);
        if(index_ida_prox == -1){
            // PROXIMO NAO EXISTE
            printf("insana\n");
            return 0;
        } else {
            no_ptr1 = nodes[index_ida_prox];
            if(no_ptr1.visitado == 1){
                // LOOP
                printf("insana\n");
                return 0;
            }
        }
        
    }

    // set ponteiros para volta
    no_ptr1 = aux_ptr1;
    no_ptr2 = aux_ptr2;

    // variaveis auxiliares para caminho volta
    long caminho_volta[quantidade_nos];
    long tamanho_caminho_volta =0;
    long index_busca_volta = 0;
    long index_volta_visitado = 0;

    while(no_ptr1.endereco_no != no_ptr2.endereco_no){
        caminho_volta[tamanho_caminho_volta] = no_ptr2.endereco_no;
        tamanho_caminho_volta++;

        // busca para marcar a visita do no da volta
        index_volta_visitado = busca_binaria(nodes,quantidade_nos, no_ptr2.endereco_no);
        nodes[index_volta_visitado].visitado = 2;

        // busca para verificar o anterior
        index_busca_volta = busca_binaria(nodes,quantidade_nos,no_ptr2.endereco_anterior);
        if(index_busca_volta == -1){
            // anterior NAO EXISTE
            printf("insana\n");
            return 0;
        } else {
            no_ptr2 = nodes[index_busca_volta];
            if(no_ptr2.visitado == 2){
                // LOOP
                printf("insana\n");
                return 0;
            }
        }
    }

    if(tamanho_caminho_ida == tamanho_caminho_volta){
        for(int i =1; i<tamanho_caminho_ida; i++){
            if(caminho_ida[i] != caminho_volta[tamanho_caminho_volta-1]){
                printf("insana\n");
                return 0;
            } 
            tamanho_caminho_volta--;
        }
        printf("sana\n");
    } else {
        printf("insana\n");
    }

    return 0;
}
