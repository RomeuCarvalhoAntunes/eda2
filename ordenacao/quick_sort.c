// QUICK SORT
// ESTRATÉGIA DE DIVIDIR PARA CONQUISTAR

// MELHO CASO: O(N Log N)
// CASO MÉDIO: O(N Log N)
// PIOR CASO:  O(N²);
// DESVANTAGEM: A escolha do pivô;
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Responsável por dividir o vetor e realizar a troca dos valores para ordenação
// colocando todos os valores menores ou maiores que o pivo a esquerda ou a direita
// dependendo do desejo do programador.
// por padrao recebe o vetor a ser ordenado, inicio(esquerda) e fim(direita)
int divide(int vector[], int esquerda, int direita){
    // variavel cont responsavel por trocar o valor correto a partir do pivo;
    // variavel auxiliar responsavel por auxiliar na troca dos valores;
    int cont;
    int auxiliar;

    cont = esquerda;

    for(int i=esquerda+1; i<=direita; i++){
        if(vector[i] < vector[esquerda]){
            cont++;
            auxiliar = vector[i];
            vector[i] = vector[cont];
            vector[cont] = auxiliar;
        }
    }

    auxiliar = vector[esquerda];
    vector[esquerda] = vector[cont];
    vector[cont] = auxiliar;

    return cont;
}

// Função quick sort trabalha de forma recursiva, onde ela recebe
// o vetor a ser ordenado o indice esquerda (início de onde ordenar até o pivo-1)
// e o indice a direita o final da ordenação, é chamada duas vezes um para ordenar
// a primeira metade e outra para ordenar a segunda metade;
void quick_sort(int vector[], int esquerda, int direita){
    // pivo é a variavel auxiliar que será responsável por ajudar no calculo divisões
    // que dividirão as metades
    int pivo;
    if(esquerda < direita){
        pivo = divide(vector, esquerda, direita);
        quick_sort(vector, esquerda, pivo-1);
        quick_sort(vector, pivo+1, direita); 
    }
}


// main responsável por receber N valores até o final do arquivo, alocando-os dinamicamente
int main(){

    int entrada_numero;
    int quantidade_numero = 0;
    int *numeros= NULL;
    int *mais_numeros = NULL;

    while( scanf("%d", &entrada_numero) != EOF){
        quantidade_numero++;
        mais_numeros = (int*) realloc (numeros, quantidade_numero * sizeof(int));
        
        if(mais_numeros != NULL){
            numeros = mais_numeros;
            numeros[quantidade_numero - 1] = entrada_numero; 
        } else {
            free(numeros);
        }
    }
    
    quick_sort(numeros, 0, quantidade_numero-1);

    for(int i=0; i<quantidade_numero; i++){
        if(i == quantidade_numero-1){
            printf("%d\n", numeros[i]);
        } else {
            printf("%d ", numeros[i]);
        }

    }


    return 0;
}

