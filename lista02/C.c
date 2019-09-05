#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

static int compara_strings(const void* nome_1, const void* nome_2){
    return strcmp(*(const char**)nome_1, *(const char**)nome_2);
}

void ordena_nome(char* nomes[], int tamanho){
    qsort(nomes,tamanho, sizeof(const char*), compara_strings);
}



int main(){

    char **nomes_alunos = NULL;
    char nome_aluno[20];

    int quantidade_alunos;
    int aluno_sorteado;

    scanf("%d %d", &quantidade_alunos, &aluno_sorteado);

    nomes_alunos = malloc (quantidade_alunos * sizeof(nome_aluno));

    for(int i=0; i<quantidade_alunos; i++){
        char* nome_aluno = (char*) malloc (sizeof(char)*20);
        scanf("%s", nome_aluno);
        nomes_alunos[i] = nome_aluno;
    }

    ordena_nome(nomes_alunos, quantidade_alunos);

    for(int i=0; i<quantidade_alunos; i++){
        if(i == aluno_sorteado-1){
           printf("%s\n", nomes_alunos[i]);
        }
    }

    return 0;
}

