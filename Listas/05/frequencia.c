#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Lista{
    int num_ascii;
    int frequencia;
}Lista;

struct Lista vetor[130];

merge(struct Lista *v, int l, int r1, int r2){
    struct Lista *v2=malloc(sizeof(Lista)*(r2-l+1));
    int k = 0;
    int i = l;
    int j = r1 + 1;
    while(i <= r1 && j <= r2){
        if(v[i].num_ascii < v[j].num_ascii){
            v2[k++] = v[i++];
        }else{
            v2[k++] = v[j++];
        }
    }
    while(i <= r1) v2[k++] = v[i++];
    while(j <= r2) v2[k++] = v[j++];
    k=0;
    for(i = l; i <= r2; i++){
        v[i] = v2 [k++];
    }
    free(v2);
}

mergeSort(struct Lista *v, int l, int r){
    if (l >= r) return 0;
    int meio = (l + r)/2;
    mergeSort(v, l, meio);
    mergeSort(v, meio+1, r);
    merge(v, l, meio, r);
}


int ascii(char *str){
    int sum[130];
    int i = 0;

    for(int i = 0; i < 130; i++){
        sum[i] = 0;
    }

    for(int i = 0; str[i] != '\0'; i++){
        sum[str[i]]++;
    }

    int tamanho = 0;
    for(int i = 0; i < 130; i++){
        if(sum[i]){
            vetor[tamanho].num_ascii = i;
            vetor[tamanho].frequencia = sum[i];
            tamanho++;
        }
    }
    return tamanho;
}



int main(){
    char s[1010];
    int tamanho;
    int ultimo;
    while (scanf(" %s", s) == 1){
        tamanho = ascii(s);

        mergeSort(vetor, 0, tamanho-1);

        for(int i = 0; i < tamanho; i++){
            printf("%d %d\n", vetor[i].num_ascii, vetor[i].frequencia);
        }
        printf("\n");
    }

    return 0;
}