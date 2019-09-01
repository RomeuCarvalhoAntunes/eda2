#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(){

    int casos=0;
    int soma=0;
    int valor=0;

    scanf("%d", &casos);
    
    for(int i=0; i<casos; i++){
        scanf("%d", &valor);
        soma += valor;
    }
    
    printf("%d\n", soma);


    return 0;
}

