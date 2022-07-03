#include <stdio.h>

void bubbleSort (int arr[], int n){
    int i, j, aux;
    for(i = 0; i < n-1; i++){
        for(j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                aux = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = aux;
            }
        }
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
    int arr[100000];
    int n;
    while (scanf("%d", &entrada) != EOF){
        arr[n] = entrada;
        n++;
    }
    bubbleSort(arr, n);
    printArray(arr, n);
    return 0;
}

// BOLHA
// Simples! Apenas ordene os números lidos da entrada padrão utilizando o Algoritmo de Ordenação BOLHA. Não tente
// trapacear rodando outra função pronta ou outro algoritmo de ordenação. Eu posso ver o seu código 8ˆ)
// ENTRADA
// A entrada possui um único caso de teste com uma quantidade arbitrária de números, a entrada termina quando o arquivo
// terminar (EOF). Os números cabem em um inteiro de 32bits.
// Sabemos que cada caso de teste não possui mais que 1000 elementos.
// SAÍDA
// Imprima os mesmos números ordenados de forma não decrescente. Os números devem ser separados por espaço e não
// deve sobrar espaço após o último número que deve ter uma quebra de linha.
// EXEMPLO
// Exemplo de Entrada
// 7 3 2 5 4 3
// Saída para o exemplo de entrada acima
// 2 3 3 4 5 7