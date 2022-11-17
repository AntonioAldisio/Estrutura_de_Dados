#include<stdio.h>
#include <stdlib.h>

typedef struct celula {
int dado;
struct celula *prox;
} celula;

void insere_inicio (celula *le, int x){
    celula *new;
    new = malloc(sizeof(celula));
    if(new == NULL){
        return 0;
    }
    new ->prox = le ->prox;
    new ->dado = x;
    le  ->prox = new;
}

void insere_antes (celula *le, int x, int y){
    celula *p, *q, *new;
    new = malloc(sizeof(celula));
    new ->dado = x;
    q = le->prox;
    p =le;
    while (q!=NULL && q->dado != y){
        p=q;
        q = q->prox;
    }
    p ->prox = new;
    new ->prox = q;

}

