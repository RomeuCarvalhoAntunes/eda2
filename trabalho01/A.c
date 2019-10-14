#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

typedef struct Node {
    unsigned int endereco_no;
    unsigned int endereco_anterior;
    unsigned int endereco_prox;
} Node;

// create merge sort here
void merge(Node* vector, int inicio, int meio, int fim){
    Node *vector_temp;
    int pivo_1, pivo_2, tamanho;
    int fim1 = 0, fim2 = 0;

    tamanho = fim-inicio+1;
    
    pivo_1 = inicio;
    pivo_2 = meio+1;

    vector_temp = (Node *) malloc (tamanho*sizeof(Node));

    if(vector_temp != NULL){
        for(int i=0; i<tamanho; i++){
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

        for(int j=0, k=inicio; j<tamanho; j++, k++){
            vector[k] = vector_temp[j];
        }
    }
    free(vector_temp);
}
void merge_sort(Node* vector, int inicio, int fim){
    int meio;
    if(inicio < fim){
        meio = floor((inicio+fim)/2);
        merge_sort(vector, inicio, meio);
        merge_sort(vector, meio+1, fim);
        merge(vector, inicio, meio, fim);
    }
}

// BUSCA BINARIA
int busca_binaria(Node* array, int tamanho, int elemento_buscado){
    int i, inicio, meio, final;
    inicio =0;
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

    unsigned int endereco;
    unsigned int anterior;
    unsigned int proximo; 
    Node ponteiro_1, ponteiro_2;
    int quantidade_nos = 0;
    Node *nodes= NULL;
    Node *more_nodes = NULL;

    while(scanf("%x %x %x", &endereco, &anterior, &proximo) != EOF){
        quantidade_nos++;
        more_nodes = (Node*) realloc (nodes, quantidade_nos * sizeof(Node));
        
        if(more_nodes != NULL){
            nodes = more_nodes;
            nodes[quantidade_nos - 1].endereco_no = endereco; 
            nodes[quantidade_nos - 1].endereco_anterior = anterior; 
            nodes[quantidade_nos - 1].endereco_prox = proximo; 
        } else {
            free(nodes);
        }
    }

    ponteiro_1 = nodes[0];
    ponteiro_2 = nodes[1];

    unsigned int caminho[quantidade_nos];
    
    Node ponteiro_1_aux, ponteiro_2_aux;
    ponteiro_1_aux = ponteiro_1;
    ponteiro_2_aux = ponteiro_2;

    merge_sort(nodes,0,quantidade_nos-1);

    for(int i=0; i<quantidade_nos; i++){
        printf("%x ", nodes[i].endereco_no);
        printf("%x ", nodes[i].endereco_anterior);
        printf("%x\n", nodes[i].endereco_prox);
    }

    int i=0;
    int index=0;
    
    while(1){
        caminho[i] = ponteiro_1_aux.endereco_no;
        index = busca_binaria(nodes,quantidade_nos, ponteiro_1_aux.endereco_prox);
        i++;
        ponteiro_1_aux = nodes[index];
        if(ponteiro_1_aux.endereco_no == ponteiro_2_aux.endereco_no){
            break;
        }
    }

    int tamanho_caminho = sizeof(caminho)/ sizeof(unsigned int);

    printf("CAMINHO IDA\n");
    
    for(int i=0; i<tamanho_caminho; i++){
        printf("%x", caminho[i]);
    }
    printf("\n");

    unsigned int caminho_inverso[quantidade_nos];
    ponteiro_1_aux = ponteiro_2;
    ponteiro_2_aux = ponteiro_1;

    int i_inverso = 0;
    int index_inverso=0;
    while(1){
        caminho_inverso[i_inverso] = ponteiro_1_aux.endereco_no;
        index_inverso = busca_binaria(nodes,quantidade_nos, ponteiro_1_aux.endereco_anterior);
        i_inverso++;
        ponteiro_1_aux = nodes[index_inverso];
        if(ponteiro_1_aux.endereco_no == ponteiro_2_aux.endereco_no){
            break;
        }
    }

    int tamanho_caminho_inverso = sizeof(caminho_inverso)/ sizeof(unsigned int);

        printf("CAMINHO VOLTA\n");

    for(int j=0; j<tamanho_caminho_inverso; j++){
        printf("%x", caminho_inverso[j]);
    }





    return 0;
}
