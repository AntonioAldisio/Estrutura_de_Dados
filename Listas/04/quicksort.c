#include <stdio.h>
#include <stdlib.h>

#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { int t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

// ajuste para size
int separa(int *v, int size){
    int l = -1;
    int r = size -1;
    int pivot = v[size-1];

    while(1){
        while(less(v[++l], pivot));
        while(less(pivot,v[--r]) && r > l);

        if(l >= r) break;
        exch(v[l], v[r]);
    }
    exch(v[l], v[size-1]);
    return l;
}


void quicksort(int *v, int size){
    if(size < 2)
        return;

    // mediana de 3 -> escolha o melhor pior
    exch(v[(size -1)/2], v[size - 2]);
    cmpexch(v[0],v[size -2]);
    cmpexch(v[0],v[size -1]);
    cmpexch(v[size - 2],v[size - 1]);
    // fim da mediana de 3

    int p = separa(v, size - 1);
    quicksort(v, p);
    quicksort(v + p + 1, size - p - 1);
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
    quicksort(arr,n);
    printArray(arr, n);
    return 0;
}