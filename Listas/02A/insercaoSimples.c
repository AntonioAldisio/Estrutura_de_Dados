# include<stdio.h>

void insercaoSimples(int arr[], int n){
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
    int arr[100000];
    int n;
    while (scanf("%d", &entrada) != EOF){
        arr[n] = entrada;
        n++;
    }
    insercaoSimples(arr, n);
    printArray(arr, n);
    return 0;
}

// Simples! Apenas ordene os números lidos da entrada padrão utilizando o Algoritmo de Ordenação INSERÇÃO. Não tente trapacear rodando outra função pronta ou outro algoritmo de ordenação. Eu posso ver o seu código 8^)
// ENTRADA

// A entrada possui um único caso de teste com uma quantidade arbitrária de números, a entrada termina quando o arquivo terminar (EOF). Os números cabem em um inteiro de 32bits.

// Sabemos que cada caso de teste não possui mais que 1000 elementos.
// SAÍDA

// Imprima os mesmos números ordenados de forma não decrescente. Os números devem ser separados por espaço e não deve sobrar espaço após o último número que deve ter uma quebra de linha.