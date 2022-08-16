#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct  {
    unsigned long long anterior;
    unsigned long long atual;
    unsigned long long prox;
}Item;

Item vetor[50000];
Item ptr1, ptr2;
int size = 0;

// ptr1 -> ptr2
int verificaIda(Item *vetor, Item ptr1, Item ptr2, int size){

}
// ptr2 -> ptr1
int verificaVolta(Item *vetor, Item ptr1, Item ptr2, int size){

}

void verificaSanidade(Item *vetor, Item ptr1, Item ptr2, int size){
   int ida = verificaIda(vetor, ptr1, ptr2, size);
   int volta = verificaVolta(vetor, ptr1, ptr2, size);
   if (ida == 1 && volta == 1)
       printf("sana\n");
   else
       printf("insana\n");
}

void entradaDados(){
    while(scanf(" %llx %llx %llx", &vetor[size].atual, &vetor[size].anterior, &vetor[size].prox) == 3){
        if(vetor[size].anterior == 0)
            ptr1 = vetor[size];
        if(vetor[size].prox == 0)
            ptr2 = vetor[size];
        size++;
    }
}

void ida (Item *v, Item ptr1, Item ptr2){
    for(int i = 0; i < size; i++){
        if(i == 0)
            printf("%llx \n", ptr1.atual);
        if (ptr1.prox == v[i].atual)
            printf("%llx \n", v[i].atual);
        if (i > 1 && v[i].prox != ptr2.atual)
            printf("%llx \n", v[i].prox);
        if (i == size - 1)
            printf("%llx \n", ptr2.atual);
    }
}

void volta (Item *v, Item ptr1, Item ptr2){
    for(int i = size; i > 0; i--){
        if(i == size){
            printf("%llx \n", ptr2.atual);
            printf("Aqui\n");
        }
        if(ptr2.anterior == v[i].atual){
            printf("%llx \n", ptr2.anterior);
            printf("Aqui2\n");
        }

    }
}

int main(){

    entradaDados();
    volta(vetor, ptr1, ptr2);
    // verificaSanidade(vetor, ptr1, ptr2, size);

    return 0;
}