#include <stdio.h>
#include <stdlib.h>
#define less(A,B) ((A) <= (B))

void merge2 (int *a, int tamanhoA, int *b, int tamanhoB){
    int *c = malloc(sizeof(int)*(tamanhoA+tamanhoB));
    int i = 0, j = 0, k = 0;
    while(i<tamanhoA && j<tamanhoB){
        if(less(a[i],b[j])){
            c[k] = a[i];
            i++;
        }else{
            c[k] = b[j];
            j++;
        }
        k++;
    }
    while(i<tamanhoA){
        c[k] = a[i];
        i++;
        k++;
    }
    while(j<tamanhoB){
        c[k] = b[j];
        j++;
        k++;
    }
    for(i=0; i<tamanhoA+tamanhoB; i++){
        a[i] = c[i];
    }
    free(c);
}

void merge(int* v, int l, int meio, int r) {
    int k = 0, i = l, j = meio+1;
    int* aux = malloc(sizeof(int)*(r-l+1));

    while (i <= meio && j <= r) {
        if (less(v[i],v[j]))
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


void mergeSort(int* v, int l, int r) {
    if (l >= r) return;

    int meio = (l+r)/2;

    mergeSort(v, l, meio);
    mergeSort(v, meio+1, r);

    merge(v, l, meio, r);
}

int dropDuplicates(int *v, int n){
    int size = 1;
    for (int i = 1; i < n; i++){
        if(v[i] != v[size-1]){
            v[size++] = v[i];        }
    }
    return size;
}

void printArray(int *arr, int n){
    int i;
    for(i = 0; i< n; i +=4){
        printf("%d \n", arr[i]);
    }
}


int main(){
    int n;
    int size;
    int adj =0;
    scanf("%d", &n);
    int *vetor = (int *)malloc(sizeof(int)*(2*n));

    for(int i = 0; i< n; i++){
        scanf("%d", &vetor[i]);
    }

    mergeSort(vetor,0,n-1);

    size = dropDuplicates(vetor, n);
    if(size % 2){
        vetor[size++] = 1000000000;
    }

    for(int i = 0; i< size-1; i += 2){
        vetor[size+adj] = vetor[i] + vetor[i+1];
        adj++;
    }

    merge2(vetor,size, vetor+size, adj);
    size = dropDuplicates(vetor, size+adj);

    printArray(vetor, size);
    printf("Elementos: %d\n", size);




    return 0;
}