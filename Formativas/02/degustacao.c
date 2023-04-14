#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Saida{
    int size;
    int posicao;
    char letra;
}Saida;


void merge(struct* v, int l, int meio, int r) {
    int k = 0, i = l, j = meio+1;
    struct* aux = malloc(sizeof(struct)*(r-l+1));

    while (i <= meio && j <= r) {
        if (aux[i].size < aux[j].size)
            aux[k++] = v[i++];
        else
            aux[k++] = v[j++];
    }

    while (i <= meio) {
        aux[k++] = v[i++];
    }

    while (j <= r) {
        aux[k++] = v[j++];
    }

    k = 0;
    for (i = l; i <= r; ++i)
        v[i] = aux[k++];

    free(aux);
}


void mergeSort(struct* v, int l, int r) {
    if (l >= r) return;

    int meio = (l+r)/2;

    mergeSort(v, l, meio);
    mergeSort(v, meio+1, r);

    merge(v, l, meio, r);
}

int main(){
    char frase[100001];
    scanf("%s", frase);

    int j=0;
    int z=0;

    struct Saida a[strlen(frase)];
    a[z].size = 0;
    int tamanho = strlen(frase);

    for(int i=0;i<tamanho;i++){
        if(frase[j]!= frase[i]){
            j=i;
            z++;
        a[z].size=0;
        }
        a[z].size++;
        a[z].posicao = j;
        a[z].letra = frase[j];
    }
    mergeSort(a,0,z);

    for(int i=z; i>=0; i--){
        printf(" %d %c %d \n", a[i].size, a[i].letra, a[i].posicao);
    }
    return 0;
}
