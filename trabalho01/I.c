#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

typedef struct Node{
    int valor;
    struct Node *esq, *dir;
}Node;


Node *newNode(int valor){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->valor = valor;
    temp->esq = temp->dir = NULL;
    return temp;
}

void print_inOrder(Node* raiz, int valor){
    if(raiz != NULL){
        if(raiz->valor == valor){
            printf("*");
        }
        print_inOrder(raiz->esq,valor);
        printf("%d ", raiz->valor);
        print_inOrder(raiz->dir,valor);
    }
}

Node* insere_node(Node* raiz, int valor){
    if(!raiz){
        raiz = newNode(valor);
        return raiz;
    } else {
        if(valor < raiz->valor){
            raiz->esq = insere_node(raiz->esq,valor);
        } else {
            raiz->dir = insere_node(raiz->dir,valor);
        }
    }
    return raiz;
}



int main(){

    Node* raiz = NULL;
    int valor;

    while (scanf("%d", &valor) != EOF) {
        raiz = insere_node(raiz,valor);
        print_inOrder(raiz,valor);
        printf(".");
        printf("\n");
    }
    return 0;
}