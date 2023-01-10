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
    while (l <= r) {
        v[l++] = aux[k++];
    }
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
    int size = 0;

    for(int i = 0; i < 8; i++){
        scanf("%d", &entrada);
        for (int j = 0; j < entrada; j++){
            scanf("%d", &arr[j+size]);
        }
        size += entrada;
        merge(arr, 0,size-entrada-1 ,size-1);

    }
    printArray(arr,size);
    return 0;
}

