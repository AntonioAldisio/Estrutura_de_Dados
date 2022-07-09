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
    int* par = malloc(sizeof(int)*(r-l+1));
    int* impar = malloc(sizeof(int)*(r-l+1));
    int numimpar = 0;
    int numpar = 0;
    for (i = l; i <= r; ++i){
        if(aux[i] & 1){
            impar[i] = aux[k++];
            numimpar++;
        }else{
            par[i] = aux[k++];
            numpar++;
        }
    }
    int total = numimpar + numpar;
    int z= 0;
    for(z =l; z<=total; z++){
        if(z <= numimpar){
            v[z] = impar[z];
        }else{
            v[z] = par[z];
        }
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
    int n;
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        scanf("%d", &entrada);
        arr[i] = entrada;
    }
    mergeSort(arr,0,n-1);
    printArray(arr, n);
    return 0;
}