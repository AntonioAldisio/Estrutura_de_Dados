#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int contaSims (char respostaQuestionario[]) {
	int contadorSims = 0;

	if (respostaQuestionario[0] == 's')
		contadorSims++;
	for (int i = 0; i < 9; i++) {
		scanf ("%s", respostaQuestionario);
		if (respostaQuestionario[0] == 's')
			contadorSims++;
	}

	return contadorSims;
}


int contaTriagens() {
	int contadorTriagens = 0;
	char respostaQuestionario[3];
	while (scanf ("%s", respostaQuestionario) != EOF) {
		if (contaSims (respostaQuestionario) > 1)
			contadorTriagens++;
	}

	return contadorTriagens;
}


int main() {

	printf("%d", contaTriagens());

}


// Ricardo é um jovem e ansioso rapaz que adora participar de Competições de Programação. Quando Ricardo fica muito ansioso por alguma coisa ele começa a tremer e acaba fazendo uma visita ao seu médico.

// O médico de Ricardo é muito metódico e sempre que recebe uma visita ele abre um questionário com perguntas simples e quando o paciente responde a sim a duas ou mais perguntas ele faz uma triagem.

// Hoje não é um dia diferente, Ricardo está muito ansioso e tremendo e por isso foi mais uma vez ao médico. Chegando ao médico Ricardo disse que está muito ansioso por causa do 8o Contest Noturno, que foi anunciado dia 12 de maio e acontecerá apenas no dia 6 de junho.

// Após se acalmar, Ricardo e seu médico ficaram conversando e perceberam que a ficha de Ricardo é enorme, e ficaram em dúvida sobre quantas vezes Ricardo precisou fazer uma triagem mais rigorosa. E para isso, pediram a sua ajuda para escrever um programa que leia os dados dos formulário do médico e diga quantas vezes Ricardo precisou da triagem.
// Entrada

// A entrada é composta por um único caso de teste contendo vários formulários. Cada formulário possui exatamente 1010 linhas, onde, cada linha possui a palavra sim ou nao, sendo a resposta para cada uma das perguntas.

// A entrada termina em EOF.
// Saída

// A saída é composta por uma única linha contendo um número inteiro informando quantas vezes Ricardo precisou fazer a triagem.
