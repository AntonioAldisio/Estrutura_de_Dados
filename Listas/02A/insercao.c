# include<stdio.h>

void insercao(int arr[], int n){
    int i, j, aux;
    for(i = 1; i < n; i++){
        aux = arr[i];
        j = i;
        while(j > 0 && arr[j-1] > aux){
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = aux;
    }
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
    int arr[50000];
    int n;
    while (scanf("%d", &entrada) != EOF){
        arr[n] = entrada;
        n++;
    }
    insercao(arr, n);
    printArray(arr, n);
    return 0;
}