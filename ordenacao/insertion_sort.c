// INSERTION SORT
// ESTÁVEL NÃO ALTERA A ORDEM DE DADOS

// cartas de baralho na mão
// MELHOR CASO : O(N)
// PIOR CASO: O(N²)

#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void insere_array(int array[]){
    int valor_aux;
    int i=0;
    while(scanf("%d", &valor_aux) != EOF){
        array[i] = valor_aux;
        i++;
    }

    insertion_sort(array,i);
}

void insertion_sort(int *ordenado, int tamanho){
    int valor_atual, valor_compara, aux_realoca;
    for(valor_atual = 1; valor_atual < tamanho; valor_atual++){
        aux_realoca = ordenado[valor_atual];
        for(valor_compara = valor_atual; (valor_compara > 0) && aux_realoca < ordenado[valor_compara-1]; valor_compara--){
            ordenado[valor_compara] = ordenado[valor_compara -1];
        }
        ordenado[valor_compara] = aux_realoca;
    }

    for(int k=0; k<tamanho; k++){
        if(k== tamanho -1){
        printf("%d\n", ordenado[k]);
        } else {
        printf("%d ", ordenado[k]);
        }

    }
}

int main(){
    int numeros[1000];
    insere_array(numeros);
    return 0;
}