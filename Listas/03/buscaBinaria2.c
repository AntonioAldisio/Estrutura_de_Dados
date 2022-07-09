#include <stdio.h>
#include <stdlib.h>
#define less(A,B) ((A) <= (B))

void printArray(int arr[], int n){
    int i;
    for(i = 0; i< n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
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

// int buscaBinaria(int *v, int l, int r, int goal){
//     if(r >= l){
//         int m = (l+r)+l/2; // meio deslocado para o inicio do vetor

//         if(v[m] == goal){
//             return m;
//         }

//         if(v[m]>goal){
//             return buscaBinaria(v, l, m-1, goal);
//         }
//         return buscaBinaria(v, m+1, r, goal);
//     }
//     return -1; // se nao encontrar o elemento
// }

int buscaBinaria(int *v, int l, int r, int goal){
    int meio = (l+r)/2;
    while(l<=r){
        if(v[meio]<goal){
            l = meio + 1;
        }
        else if(goal<v[meio]){
            r = meio - 1;
        }else{
            return meio;
        }
        meio = (l+r)/2;
    }
    return v[meio] == goal ? meio : -1;
}



int buscaLinear(int *v, int l, int r, int goal){
    for(int i = l; i <= r; i++){
        if(v[i] == goal){
            return i;
        }
    }
}


int main(){
    int N,M;
    int vetor[100000];
    int aux[100000];
    int goal;

    scanf("%d %d", &N, &M);

    for(int i = 0; i<N; i++){
        scanf("%d",&vetor[i]);
        aux[i] = vetor[i];
    }

    mergeSort(vetor,0,N-1);
    // printArray(vetor,N);

    for (int j = 0; j<M; j++){
        scanf("%d",&goal);
        // se nao existe
        if (buscaBinaria(vetor, 0, N-1, goal) == -1)
            printf("-1\n");
        else
        printf("%d\n", buscaLinear(aux, 0, N-1, goal));
    }
    return 0;
}