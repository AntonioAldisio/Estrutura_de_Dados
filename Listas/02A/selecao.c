# include<stdio.h>

void printArray(int arr[], int n){
    int i;
    for(i = 0; i< n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectSort(int arr[], int n){
    int i, j, min, aux;
    for (i = 0; i < n-1; i++){
        min = i;
        for (j = i+1; j < n; j++){
            if (arr[j] < arr[min]){
                min = j;
            }
        }
        if (min != i){
            aux = arr[i];
            arr[i] = arr[min];
            arr[min] = aux;
        }
    }
}

int main (){
    int entrada;
    int arr[100000];
    int n;
    while (scanf("%d", &entrada) != EOF){
        arr[n] = entrada;
        n++;
    }
    selectSort(arr, n);
    printArray(arr, n);
    return 0;
}

// SELEÇÃO

// Simples! Apenas ordene os números lidos da entrada padrão utilizando o Algoritmo de Ordenação SELEÇÃO. Não tente trapacear rodando outra função pronta ou outro algoritmo de ordenação. Eu posso ver o seu código 8^)
// ENTRADA

// A entrada possui um único caso de teste com uma quantidade arbitrária de números, a entrada termina quando o arquivo terminar (EOF). Os números cabem em um inteiro de 3232bits.

// Sabemos que cada caso de teste não possui mais que 10001000 elementos.
// SAÍDA

// Imprima os mesmos números ordenados de forma não decrescente. Os números devem ser separados por espaço e não deve sobrar espaço após o último número que deve ter uma quebra de linha.