#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// UTILIZAR UNSIGNED LONG LE COMO LX
// 

typedef struct Node {
    unsigned long endereco_no;
    unsigned long endereco_anterior;
    unsigned long endereco_prox;
    long imprime;
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

    unsigned long endereco;
    unsigned long anterior;
    unsigned long proximo; 
    Node ponteiro_1, ponteiro_2;
    long quantidade_nos = 0;
    Node *nodes= NULL;
    Node *more_nodes = NULL;
    Node *lista_original = NULL;

    while(scanf("%lx %lx %lx", &endereco, &anterior, &proximo) != EOF){
        quantidade_nos++;
        more_nodes = (Node*) realloc (nodes, quantidade_nos * sizeof(Node));
        
        if(more_nodes != NULL){
            nodes = more_nodes;
            nodes[quantidade_nos - 1].endereco_no = endereco; 
            nodes[quantidade_nos - 1].endereco_anterior = anterior; 
            nodes[quantidade_nos - 1].endereco_prox = proximo; 
            nodes[quantidade_nos - 1].imprime = 1; 
        } else {
            free(nodes);
        }
    }

    lista_original = (Node*) malloc(quantidade_nos*sizeof(Node));
    lista_original = nodes;

    // ponteiros para verificar o caminho
    ponteiro_1 = nodes[0];
    ponteiro_2 = nodes[1];

    unsigned int caminho[quantidade_nos];
    Node ponteiro_1_aux, ponteiro_2_aux;
    ponteiro_1_aux = ponteiro_1;
    ponteiro_2_aux = ponteiro_2;

    merge_sort(nodes,0,quantidade_nos-1);

    int i=0;
    int index=0;
    int tamanho_caminho =0;

    if(ponteiro_1_aux.endereco_no == ponteiro_2_aux.endereco_no){
        return 0;
    }
    
    do
    {
        if(i == 0){
            caminho[i] = ponteiro_1_aux.endereco_no;
            index = busca_binaria(nodes,quantidade_nos, ponteiro_1_aux.endereco_prox);
            i++;
            ponteiro_1_aux = nodes[index];
            if(ponteiro_1_aux.endereco_prox == 0 && (ponteiro_1_aux.endereco_no != ponteiro_2_aux.endereco_no)){
                return 0;
            }
            tamanho_caminho++;
        } else {
            ponteiro_1_aux = nodes[index];
            caminho[i] = ponteiro_1_aux.endereco_no;
            index = busca_binaria(nodes,quantidade_nos, ponteiro_1_aux.endereco_prox);
            i++;
            if(ponteiro_1_aux.endereco_prox == 0 && (ponteiro_1_aux.endereco_no != ponteiro_2_aux.endereco_no)){
                return 0;
            }
            tamanho_caminho++;
        }
    } while (ponteiro_1_aux.endereco_no != ponteiro_2_aux.endereco_no);



    unsigned int caminho_ptr1_inicio[quantidade_nos];
    int cnt_caminho_ptr1 =0;
    int index_ptr1=0;
    int tamanho_caminho_ptr1=0;
    ponteiro_1_aux = ponteiro_1;
    ponteiro_2_aux = ponteiro_2;

    do
    {
        caminho_ptr1_inicio[cnt_caminho_ptr1] = ponteiro_1_aux.endereco_no;
        index_ptr1 = busca_binaria(nodes, quantidade_nos, ponteiro_1_aux.endereco_anterior);
        cnt_caminho_ptr1++;
        ponteiro_1_aux = nodes[index_ptr1];
        tamanho_caminho_ptr1++;

    } while (index_ptr1 != -1);

    // MARCA OS NOS QUE PODEM SER IMPRIMIDOS
    for(int i=1; i<tamanho_caminho_ptr1; i++){
       for(int j=0; j<quantidade_nos; j++){
            if(caminho_ptr1_inicio[i] == lista_original[j].endereco_no){
                lista_original[j].imprime = 0;
            }
        }
    }

    
    unsigned int caminho_ptr2_fim[quantidade_nos];
    int cnt_caminho_ptr2 =0;
    int index_ptr2=0;
    int tamanho_caminho_ptr2=0;

    do
    {
        caminho_ptr2_fim[cnt_caminho_ptr2] = ponteiro_2_aux.endereco_no;
        index_ptr2 = busca_binaria(nodes, quantidade_nos, ponteiro_2_aux.endereco_prox);
        cnt_caminho_ptr2++;
        ponteiro_2_aux = nodes[index_ptr2];
        tamanho_caminho_ptr2++;

    } while (index_ptr2 != -1);


    for(int i=1; i<tamanho_caminho_ptr2; i++){
       for(int j=0; j<quantidade_nos; j++){
            if(caminho_ptr2_fim[i] == lista_original[j].endereco_no){
                lista_original[j].imprime = 0;
            }
        }
    }

    for(int i=0; i<tamanho_caminho; i++){
        for(int j=0; j<quantidade_nos; j++){
            if(caminho[i] == lista_original[j].endereco_no){
                lista_original[j].imprime = 1;
            }
        }
    }


    for(int j=0; j<quantidade_nos; j++){
        if(lista_original[j].imprime == 0){
            printf("%x %x %x", lista_original[j].endereco_no, lista_original[j].endereco_anterior,lista_original[j].endereco_prox);
            printf("\n");
        }
    }

    printf("\n");   
    for(int i=0; i<tamanho_caminho; i++){
        printf("%x\n", caminho[i]);
    }

    printf("\n");
    
    return 0;
}
