#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int n){
    int i;
    for(i = 0; i< n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int buscaBinaria(int *v, int l, int r, int goal){
    int m = (l +r)/2;
    while(l <= r){
        if(v[m] == goal){
            return m;
        }
        if(v[m] < goal){
            l = m + 1;
        }
        else{
            r = m - 1;
        }
        m = (l + r)/2;
    }
    if (v[m]<goal){
        ++m;
    }
    return m;
}


int main(){
    int N,M;
    int vetor[1000000];
    int goal;

    scanf("%d %d", &N, &M);

    for(int i = 0; i<N;i++){
        scanf("%d",&vetor[i]);
    }
    for (int j = 0; j<M; j++){
        scanf("%d",&goal);
        printf("%d\n", buscaBinaria(vetor, 0, N-1, goal));
    }
    return 0;
}