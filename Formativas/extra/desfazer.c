#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula {
char dado[100];
struct celula *prox;
} celula;

celula *p;

void criarpilha(void){
    p = malloc (sizeof (celula));
    p->prox = NULL;
}

void empilha (char x[]){
    celula *new;
    new = malloc(sizeof(celula));
    new ->prox = p ->prox;
    for(int i =0; i<100 ;i++){
        new ->dado[i] = x[i];
    }
    p->prox = new;
}

void desempilha (void){
    char y[100];
    celula *lixo;
    lixo = p->prox;
    if(lixo == NULL){
        printf("NULL\n");
    }else{
        p->prox = lixo->prox;
        for(int i =0; i<100;i++){
            y[i] = lixo->dado[i];
        }
        printf("%s\n",y);
        free(lixo);
    }
}


int main(){

    char entrada[100];
    char check[8];
    char mensagem[100];
    char saida[3];
    criarpilha();
    while(scanf("%s", entrada) > 0 ){
        for(int i =0; i<7; i++){
            check[i] = entrada[i];
        }
        if(strcmp(check,"inserir")==0){
            scanf(" %[^\n]s", mensagem);
            empilha(mensagem);
        }else{
            desempilha();
        }

    }
    return 0;
}