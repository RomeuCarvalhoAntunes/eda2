#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

typedef struct NodeRB {
    long long numero_proibido;
    char cor;
    struct NodeRB *esquerda, *direita, *parente;
} NodeRB; 

void rotacao_esquerda(NodeRB **raiz, NodeRB *node){
    if(!node || !node->direita){
        return ;
    }

    NodeRB *no_temp = node->direita;
    node->direita = no_temp->esquerda;

    if(node->direita != NULL){
        node->direita->parente = node;
    }

    no_temp->parente = node->parente;

    if(node->parente == NULL){
        (*raiz) = no_temp;
    }

    else if(node == node->parente->esquerda){
        node->parente->esquerda = no_temp;
    } else {
        node->parente->direita = no_temp;
    }

    no_temp->esquerda = node;
    node->parente = no_temp;

}

void rotacao_direita(NodeRB **raiz, NodeRB *node){
    if(!node || !node->esquerda){
        return;
    }
  
    NodeRB *no_temp = node->esquerda;
    node->esquerda = no_temp->direita;

    if(no_temp->direita != NULL){
        no_temp->direita->parente = node;
    } 
   
    no_temp->parente = node->parente;

    if(no_temp->parente == NULL){
        (*raiz) = no_temp;
    }

    else if( node = node->parente->esquerda){
        node->parente->esquerda = no_temp;
    } else {
        node->parente->direita = no_temp;
    }

    no_temp->direita = node;
    node->parente = no_temp;


}

void arruma_insert(NodeRB **raiz, NodeRB *node){
    while(node != *raiz &&
     node != (*raiz)->esquerda &&
     node != (*raiz)->direita &&
     node->parente->cor == 'R'){

        NodeRB *no_temp;

        if(node->parente &&
        node->parente->parente &&
        node->parente == node->parente->parente->esquerda){
            no_temp = node->parente->parente->direita;
        } else {
            no_temp = node->parente->parente->esquerda;
        }

        if(!no_temp){
            node = node->parente->parente;
        }

        else if(no_temp->cor == 'R'){
            no_temp->cor = 'B';
            node->parente->cor = 'B';
            node->parente->parente->cor = 'R';
            node = node->parente->parente;
        } 

        else {
            if(node->parente == node->parente->parente->esquerda &&
            node == node->parente->esquerda){
                char ch = node->parente->cor;
                node->parente->cor = node->parente->parente->cor;
                node->parente->parente->cor = ch;
                rotacao_direita(raiz,node->parente->parente);
            }

            if(node->parente &&
            node->parente->parente && 
            node->parente == node->parente->parente->esquerda &&
            node == node->parente->direita){
                char ch = node->cor;
                node->cor = node->parente->parente->cor;
                node->parente->parente->cor = ch;
                rotacao_esquerda(raiz, node->parente);
                rotacao_direita(raiz, node->parente->parente);
            }

            if(node->parente &&
            node->parente->parente &&
            node->parente == node->parente->parente->direita &&
            node == node->parente->direita){
                char ch = node->parente->cor;
                node->parente->cor = node->parente->parente->cor;
                node->parente->parente->cor = ch;
                rotacao_esquerda(raiz,node->parente->parente);
            }

            if(node->parente &&
            node->parente->parente &&
            node->parente == node->parente->parente->direita &&
            node == node->parente->esquerda){
                char ch = node->cor;
                node->cor = node->parente->parente->cor;
                node->parente->parente->cor = ch;
                rotacao_direita(raiz, node->parente);
                rotacao_esquerda(raiz, node->parente->parente);
            }
        }
    }
    (*raiz)->cor = 'B';
}

void insert(NodeRB **raiz, long long numero_proibido){
    NodeRB *node = (NodeRB*) malloc(sizeof(NodeRB));
    node->numero_proibido = numero_proibido;
    node->esquerda = node->direita = node->parente = NULL;

    if(*raiz == NULL){
        node->cor = 'B';
        (*raiz) = node;
    } else {
        NodeRB *y = NULL;
        NodeRB *x = (*raiz);

        while(x != NULL){
            y = x;
            if(node->numero_proibido < x->numero_proibido){
                x = x->esquerda;
            } else {
                x = x->direita;
            }
        }
        node->parente = y;
        if(node->numero_proibido > y->numero_proibido){
            y->direita = node;
        } else {
            y->esquerda = node;
        }
        node->cor = 'R';
        arruma_insert(raiz,node);
    }
}

// void inorder(NodeRB *root)
// {
//     static int last = 0;
//     if (root == NULL)
//         return;
//     inorder(root->esquerda);
//     printf("%lld ", root->numero_proibido);
//     if (root->numero_proibido < last)
//         printf("\nPUTE\n");
//     last = root->numero_proibido;
//     inorder(root->direita);
// }

void busca_red_black(NodeRB *raiz, int numero_proibido){
    if(!raiz){
        printf("nao\n");
    } else if( numero_proibido < raiz->numero_proibido){
        busca_red_black(raiz->esquerda, numero_proibido);
    } else if(numero_proibido > raiz->numero_proibido){
        busca_red_black(raiz->direita, numero_proibido);
    } else {
        printf("sim\n");
    }
}

int main(){
    
    NodeRB *raiz = NULL;
    long long quantidade_numeros;
    long long numero_proibido;

    scanf("%lld", &quantidade_numeros);

    for(long long i=0; i<quantidade_numeros; i++) {
        scanf("%lld", &numero_proibido);
        insert(&raiz, numero_proibido);
    }

    long long numero_buscado;

    while (scanf("%lld", &numero_buscado) != EOF)
    {
        busca_red_black(raiz,numero_buscado);
    }

    return 0;
}

