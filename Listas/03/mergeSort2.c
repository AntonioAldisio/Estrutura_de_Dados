#include <stdio.h>
#include <stdlib.h>
#define less(A,B) ((A) <= (B))

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

void printArray(int arr[], int n){
    int i;
    for(i = 0; i< n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main (){
    int entrada;
    int arr[1000000];
    int n;
    while (scanf("%d", &entrada) != EOF){
        arr[n] = entrada;
        n++;
    }
    mergeSort(arr,0,n-1);
    printArray(arr, n);
    return 0;
}