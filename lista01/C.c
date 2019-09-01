#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(){

    int quantidade=0;
    int valor=0;

    while(scanf("%d", &valor) != EOF){
        quantidade++;
    }

    printf("%d\n", quantidade);

    return 0;
}

