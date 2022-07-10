# QuickSort

## 1. Introdução

O quicksort adota a estratégia de divisão e conquista. A estratégia consiste em rearranjar as chaves de modo que as chaves "menores" precedam as chaves "maiores". Em seguida o quicksort ordena as duas sublistas de chaves menores e maiores recursivamente até que a lista completa se encontre ordenada. [3]Os passos são:

- Escolha um elemento da lista, denominado pivô;
- Particiona: rearranje a lista de forma que todos os elementos anteriores ao pivô sejam menores que ele, e todos os elementos posteriores ao pivô sejam maiores que ele. Ao fim do processo o pivô estará em sua posição final e haverá duas sub listas não ordenadas. Essa operação é denominada partição;
- Recursivamente ordene a sub lista dos elementos menores e a sub lista dos elementos maiores;

O caso base da recursão são as listas de tamanho zero ou um, que estão sempre ordenadas. O processo é finito, pois a cada iteração pelo menos um elemento é posto em sua posição final e não será mais manipulado na iteração seguinte.

A escolha do pivô e os passos do Particiona podem ser feitos de diferentes formas e a escolha de uma implementação específica afeta fortemente a performance do algoritmo.

~~~C
// Separa - Do jeito que gasta mais memoria
// Precisa de duas vezes maior o vetor
int sepera (Item *v, int l, int r){
    int tamanhoTotal = (r - l) + 1;
    Item *menores = malloc(sizeof(Item)*tamanhoTotal);
    Item *maiores = malloc(sizeof(Item)*tamanhoTotal);
    Item c =v [r] // Meu Pivo

    int imenor =0 , imaior = 0;

    for(int i=l; i<r;i++){
        if(less(v[i],c)){
            menores[imenor++]=v[i];
        }else
            maiores[imaior++]=v[i];

    }
    int i =l;
    for (int j =0; i <imenor; j++){
        v[i++] = v[j];
    }
    v[i] = c;
    int cpos;
    cpos = i;

    for(int j =0; j<imaiores; j++){
        v[i++]=maiores[j];
    }
    free(menores);
    free(maiores);

    retunr cpos;

}
~~~

~~~C
// Separa mais adequado
int separa(Item *v, int l, int r){
    Item c = v[r]; // pivo
    int j = l;

    for(int k=l; k<r; k++){
        if(lesseq(v[k],c)){
            exch(v[k],v[j]);
            j++;
        }
        exch(v[j],v[r]);
    }
    return j;
}
~~~

~~~C
// Separa do Sergio
int separa(Item *v, int l, int r){
    int i =l-1;
    int j = r;
    Item c = v[r] // pivo
    for(;;){
        while(less(v[++i],c));
        while(less(c,v[--j]))
            if(j == l)
                break;
        if (i >= j)
            break;
        exch(v[i],v[j]);
    }
    exch(v[i],v[r]);
    return i;
}
~~~

Separa é estavel ?

> Não.

~~~C
// quickSort ingenio
void quickSort(Item *v, int l, int r){
    int j;
    if (r<=l) return;
    j = separa(v,l,r);
    quickSort(v,l,j-1);
    quickSort(v,j+1,r);
}
~~~

~~~C
// Mediana de três elementos
void quickSort(Item *v, int l, int r){
    int j;
    if (r<=l) return;

    // mediana de 3 -> escolha o melhor pior
    cmpexch(v[(l+r)/2],v[r]);
    cmpexch(v[l],v[(l+r)/2]);
    cmpexch(v[r],v[(l+r)/2]);
    // fim da mediana de 3

    j = separa(v,l,r);
    quickSort(v,l,j-1);
    quickSort(v,j+1,r);
}
~~~

O Quick Sort não é um algoritmo estável. O modo como o particiona é implementado permite que elementos iguais troquem de posições relativas durante a sua execução.