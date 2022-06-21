#include <stdio.h>

int main(){
    int i = 0;
    int x = 0;
    int y = 0;
    int tamanho;

    scanf("%d",&tamanho);
    for(i =0; i< tamanho; i++){

        scanf("%d",&x);
        y = x+y;
    }

    printf("%d \n",y);


    return 0;
}
// Bem vindo ao terceiro exercício!

// No exercício anterior trabalhamos apenas com o processamento de uma entrada bastante simples, pois toda entrada possuia um número fixo de números a serem lidos, nem sempre isso é verdade!

// Para este exercício você deve ler um conjunto de números da entrada padrão (geralmente o teclado) e imprimir uma única linha contendo a soma de todos eles.
// Entrada

// A entrada é composta de um único caso de teste. A primeira linha contém um inteiro positivo N. As N linhas seguintes contêm cada uma um inteiro X, representando os N números a serem somados.
// Saída

// Seu programa deve produzir uma única linha na saída, contendo a soma de todos os N inteiros.
// Restrições

//     0 ≤ N ≤ 50
//     |X| ≤ 5000

// Exemplo de Entrada

// 2
// 2
// 3

// Exemplo de Saída

// 5