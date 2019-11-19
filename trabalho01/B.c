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
    unsigned long caminho_ida[quantidade_nos];
    unsigned long tamanho_caminho_ida = 0;
    unsigned long index_ida_prox = 0;
    unsigned long index_ida_visitado = 0;

    // constroi caminho de ida
    while(no_ptr1.endereco_no != no_ptr2.endereco_no){
        caminho_ida[tamanho_caminho_ida] = no_ptr1.endereco_no;
        tamanho_caminho_ida++;

        // busca para verificar se o no prox existe
        index_ida_prox = busca_binaria(nodes,quantidade_nos,no_ptr1.endereco_prox);
        no_ptr1 = nodes[index_ida_prox];        
    }


    unsigned long caminho_antes_ptr1[quantidade_nos];
    unsigned long tamanho_antes_ptr1 = 0;
    long index_anterior = 0;
    no_ptr1 = aux_ptr1;

    while(index_anterior != -1){

        caminho_antes_ptr1[tamanho_antes_ptr1] = no_ptr1.endereco_no;
        tamanho_antes_ptr1++;

        index_anterior = busca_binaria(nodes, quantidade_nos, no_ptr1.endereco_anterior);
        no_ptr1 = nodes[index_anterior];

    }



    unsigned long caminho_depois_ptr2[quantidade_nos];
    unsigned long tamanho_depois_ptr2 = 0;
    long index_prox = 0;
    no_ptr2 = aux_ptr2;



    while(index_prox != -1){
        caminho_depois_ptr2[tamanho_depois_ptr2] = no_ptr2.endereco_no;
        tamanho_depois_ptr2++;
        index_prox = busca_binaria(nodes,quantidade_nos,no_ptr2.endereco_prox);
        no_ptr2 = nodes[index_prox];
    }

    if(tamanho_antes_ptr1 > 1){
        long idx_prox = busca_binaria(nodes,quantidade_nos, caminho_antes_ptr1[1]);
        nodes[idx_prox].endereco_prox = caminho_depois_ptr2[1];
    }

    unsigned long index_visitado_antes=0;
    for(long i=tamanho_antes_ptr1-1; i>0; i--){
        index_visitado_antes = busca_binaria(nodes, quantidade_nos, caminho_antes_ptr1[i]);
        nodes[index_visitado_antes].visitado = 1;
        printf("%lx %lx %lx\n", nodes[index_visitado_antes].endereco_no, nodes[index_visitado_antes].endereco_anterior, nodes[index_visitado_antes].endereco_prox );
    }

    if(tamanho_depois_ptr2 > 1){
        long index_atualiza_anterior = busca_binaria(nodes, quantidade_nos, caminho_depois_ptr2[1]);
        nodes[index_atualiza_anterior].endereco_anterior = caminho_antes_ptr1[1];
    } 

    unsigned long index_visitado_depois=0;
    for(long i=1; i<tamanho_depois_ptr2; i++){
        index_visitado_depois = busca_binaria(nodes, quantidade_nos, caminho_depois_ptr2[i]);
        nodes[index_visitado_depois].visitado = 1;
        printf("%lx %lx %lx\n", nodes[index_visitado_depois].endereco_no, nodes[index_visitado_depois].endereco_anterior, nodes[index_visitado_depois].endereco_prox );
    }

    printf("\n");
    for(long i=0; i<tamanho_caminho_ida; i++){
        printf("%lx\n", caminho_ida[i]);
    }
    printf("%lx\n", aux_ptr2.endereco_no);



    return 0;
}
