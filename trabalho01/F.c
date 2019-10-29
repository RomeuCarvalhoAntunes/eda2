#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

typedef struct Hash {
    int quantidade_elementos;
    int tamanho_tabela;
    int lapide;
    char **codigo; 
} Hash;


// cria tabela
Hash* cria_tabela(int tamanho_tabela){
    Hash* tabela_ha = (Hash*)malloc(sizeof(Hash));
    if(tabela_ha != NULL){
        tabela_ha->tamanho_tabela = tamanho_tabela;
        tabela_ha->codigo = (char**) malloc(tamanho_tabela * sizeof(char*) * 1002);
        if(tabela_ha->codigo == NULL){
            free(tabela_ha);
            return NULL;
        }
        tabela_ha->quantidade_elementos = 0;
        for(int i=0; i<tabela_ha->tamanho_tabela; i++){
            tabela_ha->codigo[i] = NULL;
            tabela_ha->lapide = 0;
        }
    }
    return tabela_ha;
}

// deleta tabela
void libera_hash(Hash* tabela){
    if(tabela != NULL){
        for(int i=0; i<tabela->tamanho_tabela; i++){
            if(tabela->codigo[i] != NULL){
                free(tabela->codigo[i]);
            }
        }
        free(tabela->codigo);
        free(tabela);
    }
}

int enderecamento_aberto(int pos, int tentativa){
    return ((pos + (23*tentativa)) + (tentativa * tentativa)) % 101;
}

int funcao_hash(char* codigo){
    int chave=0;
    for(int i=0; i<codigo[i]; i++){
        chave += (int) codigo[i] * (i+1);
    }
    return (chave * 19) % 101;
}

// FUNCAO ADD
int insere_hash_endereco_aberto(Hash* tabela, char *codigo){
    
    if(tabela == NULL  || tabela->quantidade_elementos == tabela->tamanho_tabela){
        return 0;
    }

    int pos = 0, next_pos = 0;
    char *id = codigo;
    pos = funcao_hash(id);
    // so pode tentar inserir 19 vezes;
    for(int k=1; k<=19; k++){
        // funcao de encademento aberto;
        next_pos = enderecamento_aberto(pos,k);
        if(tabela->codigo[next_pos] == NULL){
            char * novo;
            novo = (char *) malloc(sizeof(char));
            if(novo == NULL){
                return 0;
            }
            novo = codigo;
            tabela->codigo[next_pos] = novo;
            tabela->quantidade_elementos++;
            return 1;
        }
    }
    return 0;
}

// FUNCAO PARA DELETAR DENTRO DA TABELA HASH
int deleta_hash_endereco_aberto(Hash *tabela, char* codigo){
    for(int i=0; i<101; i++){
        if(tabela->codigo[i] == codigo){
            tabela->codigo[i] = NULL;
            tabela->quantidade_elementos--;
            return 1;
        }
    }
    return 0;
}

int main(){

    int casos_teste;
    int numero_operacoes;
    Hash* tabela;

    scanf("%d", &casos_teste);
    for(int i=0; i<casos_teste; i++){

        scanf("%d", &numero_operacoes);
        tabela = cria_tabela(101);

        for(int j=0; j<numero_operacoes; j++){
           
            char operacao[100];
            scanf("%s", operacao);
            char *codigo = operacao + 4;
            
            if(operacao[0] == 'A'){
                insere_hash_endereco_aberto(tabela, codigo);
            }
            if(operacao[0] == 'D'){
                deleta_hash_endereco_aberto(tabela,codigo);
            }
        }

        printf("%d\n", tabela->quantidade_elementos);
        for(int i=0; i< tabela->tamanho_tabela; i++){
            if(tabela->codigo[i]!= NULL){
                printf("%d:%s\n", i, tabela->codigo[i]);
            }
        }

    }

    // libera_hash(tabela);

    return 0;
}