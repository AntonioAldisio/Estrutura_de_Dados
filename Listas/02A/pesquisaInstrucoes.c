#include <stdio.h>
#include <stdlib.h>

#define key(A) (A.codigo)
#define less(A, B) (key(A) < key(B))
#define	exch(A,B) { instrucao T = A; A = B; B = T; }
#define lessExch(A, B) { if less(B, A) exch(B, A); }


typedef struct {
	char comando[15];
	int codigo;
} instrucao;


void recebeInputs(instrucao *inputs, int n) {
	for (int i = 0; i < n; i++) {
		scanf("%d %s", &inputs[i].codigo, inputs[i].comando);
	}
}

void sort(int l, int r, instrucao *vetor, int salto) {
	for (int i = l + salto; i <= r; i++) {
		int j = i;
		instrucao tmp = vetor[i];
		while (j >= l + salto && less(tmp, vetor[j - salto])) {
			vetor[j] = vetor[j - salto];
			j -= salto;
			vetor[j] = tmp;
		}
	}
}

void shellSort(int l, int r, instrucao *vetor) {
	int h;
	for (h = 1; h <= (r - l)/9; h = 3*h + 1);
	while (h > 0) {
		sort(l, r, vetor, h);
		h /= 3;
	}
}


void buscaBinaria(instrucao *vetor, int final, int codigo) {
	int inicio = 0;
    int meio;
    while (inicio <= final) {
        meio = (inicio + final) / 2;
        if (vetor[meio].codigo == codigo) {
            printf("%s\n", vetor[meio].comando);
            return;
        }
        if (vetor[meio].codigo < codigo) {
            inicio = meio + 1;
        } else {
            final = meio - 1;
        }
    }
	printf("undefined\n");
}

int main(void) {
	int n, codigo;
	instrucao *inputs;
	scanf("%d", &n);

	inputs = malloc(n*sizeof(instrucao));
	if (inputs == NULL) exit(1);

	recebeInputs(inputs, n);
	shellSort(0, n - 1, inputs);

	while(scanf("%d", &codigo) != EOF) {
		buscaBinaria(inputs, n, codigo);
	}
	free(inputs);
	return 0;
}

// Pesquisa de instruções

// A equipe do Fórum de GCC e Assemblers (FGA) está desenvolvendo uma ferramenta de engenharia reversa que, dado um código em linguagem de máquina, deseja convertê-lo novamente num código em linguagem de alto nível (alguma das quais o GCC dá suporte). Há inúmeros módulos que precisam ser desenvolvidos, e você faz parte da equipe de desenvolvimento. O gerente do projeto te designou a seguinte tarefa: você tem que desenvolver um programa que lê o código de uma instrução em linguagem de máquina e devolve a correspondente da linguagem de alto nível. Por exemplo, se o seu programa ler o código 20, ele deve devolver o for. Como você acabou de aprender um algoritmo de busca bem eficiente, você decide fazer um programa que carrega na memória todas as instruções, e seus respectivos códigos, e depois responde às pesquisas demandadas ao seu programa.
// Entrada

// A entrada é composta de diversas linhas. A primeira linha contém um inteiro nn que determina quantas instruções você precisa carregar na memória. As nn linhas seguintes contém um inteiro e uma palavra que caracterizam uma instrução: o primeiro é o código da instrução, e a segunda a palavra-chave com, no máximo, 15 caracteres. As demais linhas são inteiros que correspondem aos códigos de instruções para os quais você precisa determinar a palavra-chave correspondente. A entrada termina com EOF.
// Saída

// A saída é composta pela mesma quantidade de consultas feitas na entrada. Para cada inteiro consultado, você deve imprimir a palavra-chave correspondente. Se a palavra chave não fizer parte do conjunto de instruções, você deve imprimir undefined.