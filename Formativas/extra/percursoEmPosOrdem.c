#include<stdio.h>
#include <stdlib.h>

typedef struct no {
int dado;
struct no *esq, *dir;
} no;

// Sem recursividade
void pos_ordem (no *raiz){
    no *pilha[100];
    int topo = -1;
    no *atual = raiz;
    no *anterior = NULL;
    while(atual != NULL || topo != -1){
        while(atual != NULL){
            topo++;
            pilha[topo] = atual;
            atual = atual->esq;
        }
        atual = pilha[topo];
        topo--;
        if(atual->dir == NULL || atual->dir == anterior){
            printf("%d ", atual->dado);
            anterior = atual;
            atual = NULL;
        }else{
            topo++;
            pilha[topo] = atual;
            atual = atual->dir;
        }
    }
}