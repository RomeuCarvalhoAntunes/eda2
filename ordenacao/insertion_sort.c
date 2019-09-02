// INSERTION SORT
// CARTA DE BARALHO NA MÃO;

// MELHOR CASO : O(N);
// PIOR CASO: O(N²);
// Algoritmo estável onde a ordem de dois elementros iguais não é alterada;

#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Por padrão a função do insertion sort vai receber o vetor que vai ordenar e o tamanho do vetor;
int insertion_sort(int vetor[], int tamanho_vetor){
    // Variáveis auxiliares;
    // Variável "i" responsável por escolher o número que iremos ordenar dentro do vetor;
    // Variável "j" responsável por percorrer o vetor para verificar a posição de inserção;
    // Variável "auxiliar" reponsável por realizar o swap quando encontrar a posição adequada;
    // Ordenação em ordem crescente
    int i=0, j=0, auxiliar; 
    for(i=1; i < tamanho_vetor; i++){
        j = i;
        while( j > 0 && vetor[j] < vetor[j-1]){
            auxiliar = vetor[j];
            vetor[j] = vetor[j-1];
            vetor[j-1] = auxiliar;
            j--;
        }
    }
}

void print_array(int vetor[], int tamanho_vetor){
    for(int i=0; i<tamanho_vetor; i++){
        printf("%d ", vetor[i]);
    }
}

int main(){

    int array_desordenado[15] = {-8,10,56,814,587,317,-57,9,27,86,1,89,20,35,67} ;
    insertion_sort(array_desordenado,15);
    print_array(array_desordenado,15);
    return 0;
}