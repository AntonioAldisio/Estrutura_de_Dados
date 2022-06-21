#include<stdio.h>

int main(){

   int contador =0;
   int entrada;

   while(scanf("%d",&entrada) == 1){
       contador++;
   }
   printf("%d \n", contador);

return 0;
}
// EOF (End Of File) representa o fim de arquivo. Enquanto se está lendo um arquivo e não existe mais conteúdo a ser lido é gerada essa informação no sistema, EOF, dizendo que o arquivo acabou.

// A entrada padrão também é considerada um arquivo e em uma execução sem redirecionamento a combinação ^d (control + d) gera um EOF. Quando a acontece o redirecionamento (a execução no estilo: ./meuprograma < arquivo) o conteúdo do arquivo é enviado ao programa pela entrada padrão e quando todo o conteúdo do arquivo for consumido o EOF será gerado.

// A função scanf no C, trata esse efeito. Por isso ela deve ser bem estudada. Como um resumo rápido: A função scanf retorna quantos elementos de % foram lidos com sucesso, então uma chamada do tipo:

// scanf("%d %lf", &a,&b)

// Retornará 2 quando ambos números forem lidos com sucesso, e:

// scanf("%s %d %s %d",str1,&a,str2,&b)

// Retornará 4 quando todos forem lidos com sucesso, e:

// scanf("%d",&a)

// Retornará 1 quando o número for lido com sucesso.