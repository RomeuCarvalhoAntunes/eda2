// BUSCA BINÁRIA
// DIVISÕES SUCESSIVAS PARA ACHAR O ELEMENTO

// MELHOR CASO: O (1)
// CASO MÉDIO: O (Log N)
// PIOR CASO: O (Log N)


#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>


// Recebe o array onde será realizada a busca, o tamanho do array,
// e o elemento buscado;
// o vetor precisa estar ordenado;
// equanto existirem elementos entre o inicio e o fim calcula o meio do vetor;
// se o elemento for maior que o meio busca na direita;
// se for menor busca na esquerda do vetor;
// se ele for igual ao meio o elemento foi encontrado;
// se nao for nenhuma das alternativas o elemento nao existe no vetor;
int busca_binaria(int array[], int tamanho, int elemento_buscado){
    int i, inicio, meio, final;
    inicio =0;
    final = tamanho-1;
    while(inicio <= final){
        meio = (inicio + final)/2;
        if(elemento_buscado < array[meio]){
            final = meio - 1;
        } else {
            if(elemento_buscado > array[meio]){
                inicio = meio+1;
            } else {
                printf("sim\n");
                return meio;
            }
        }
    }
    printf("nao\n");
    return -1;
}

// Array qualquer declarado apenas para estudo, nesse caso números primos;
// Buscas binárias sucessivas no array até final do arquivo de entrada;
int main(){

    int array_primos[11] = {1,2,3,5,7,11,13,17,19,23,29};
    int numero_teste;
    int resposta_busca;

    while(scanf("%d", &numero_teste) != EOF){
        busca_binaria(array_primos,11,numero_teste);
    }
    


    return 0;
}

