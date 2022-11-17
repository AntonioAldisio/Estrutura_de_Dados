#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
int dado;
struct celula *prox;
} celula;

void imprime (celula *le){
    celula *elem;
    for(elem = le ->prox; elem != NULL;elem = elem->prox){
        printf("%d -> ", elem->dado);
    }
    printf("NULL\n");
}

void imprime_rec (celula *le){
    celula *elem;
    elem = le->prox;
    if(elem != NULL){
       printf("%d ->", elem->dado);
        imprime_rec(le->prox);
    }else{
        printf("NULL\n");
    }
}

/*
int main(){
    celula *le = malloc(sizeof(celula));

    imprime(le);
    imprime_rec(le);
    free(le);


    return 0;
}
*/