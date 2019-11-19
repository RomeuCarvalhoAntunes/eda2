#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int funcao_hash(char *codigo){
    int chave = 0;
    for(int i=0; codigo[i]; i++){
        chave += (int)codigo[i] * (i+1);
    }
    return (chave *19) % 101;
}

int enderecamento_aberto(int posicao, int tentativa){
    return (posicao + (23 * tentativa) + (tentativa*tentativa)) % 101;
}

int insere_tabela(char **tabela, char *codigo){
    if(tabela != NULL){
        int posicao = funcao_hash(codigo);
        int new_pos =0;

        if(strcmp(tabela[posicao], codigo) == 0){
            return 0;
        } else {
            for(int i=1; i<=19; i++){
                new_pos = enderecamento_aberto(posicao, i);
                if(strcmp(tabela[new_pos], codigo) ==0){
                    return 0;
                }
            }
        }

        if(strcmp(tabela[posicao], "") == 0){
            strcpy(tabela[posicao], codigo);
            return 1;
        } else {
            for(int i=1; i<= 19; i++){
                new_pos = enderecamento_aberto(posicao,i);
                if(strcmp(tabela[new_pos], "") == 0){
                    strcpy(tabela[new_pos], codigo);
                    return 1;
                }
            }
        }
    }
    return 0;
}

int deleta_tabela(char **tabela, char *codigo){
    for(int i=0; i<101; i++){
        if(strcmp(tabela[i], codigo) == 0){
            strcpy(tabela[i], "");
            return 1;
        }
    }
    return 0;
}


int main(){

    char **tabela;
    int testes =0;
    scanf("%d", &testes);

    while (testes--){
        tabela = malloc(sizeof(char*) * 101);
        for(int i=0; i< 101; i++){
            tabela[i] = malloc (sizeof(char)* 1002);
        }
        int quantidade =0;
        int instrucoes;
        scanf("%d", &instrucoes);
        while (instrucoes--){
            char operacao[30];
            scanf("%s", operacao);
            char *codigo = operacao +4;
            if(operacao[0] == 'A'){
               if(insere_tabela(tabela, codigo)){
                    quantidade++;
               }
            }
            if(operacao[0] == 'D'){
                if(deleta_tabela(tabela, codigo)){
                    quantidade--;
                }
            }
        }
        printf("%d\n", quantidade);
        for(int i=0; i<101;i++){
            if(strcmp(tabela[i], "") != 0)
                printf("%d:%s\n", i, tabela[i]);
        }
    }
    free(tabela);
    return 0;
}