# Algortimos de ordenação elementares

## 1. Select Sort

A ordenação por seleção (do inglês, selection sort) é um algoritmo de ordenação baseado em se passar sempre o menor valor do vetor para a primeira posição (ou o maior dependendo da ordem requerida), depois o de segundo menor valor para a segunda posição, e assim é feito sucessivamente com os n-1 elementos restantes, até os últimos dois elementos. Em resumo, ele procura o menor elemento do vetor e coloca no inicio.

O algoritmo não é estável.

~~~C
void selectionSort (Item *v, int l, int r){
    for (int i = 0; i < r; i++){
        int min = i;
        for (int j = i+1; j <= r; j++){
            if(less(v[j],v[min])){
                min = j;
            }
        }
        exch(v[min],v[l]);
    }
}
~~~

~~~C
void selectionSort (Item *v, int l, int r){
    if(l == r) return;
    int min = l;
    for (int j = l+1; j <= r; j++){
        if(less(v[j],v[min])){
            min = j;
        }
    }
    exch(v[min],v[l]);
    selectionSort(v, l+1, r);
}
~~~

## 2. Ordenação por Bolha

Algoritmo mais simples de ordenação.
Ele sempre ira se comportar de maneira pior comparado comos outros.
É um algoritmo de ordenação estável.

Ideia do Algoritmo:

- Pecorrar o vetor inteiro comparando elementos adjacentes (dois a dois).
- Troque as posiçōes dos elementos se estiverem fora de ordem.
- Repita os dois passos acima com os primeiros n-1 itens, depois com os primeiros n-2 itens, até que reste apenas um item.

~~~C
void bolha (Item *v, int l, int r){
    for(int i = l; i< r; i++){
        for(int j = l; j < r; j++){
            if(less(v[j+1],v[j])){
                exch(v[j+1],v[j]);
            }
        }
    }
}
~~~

## 3. Insertion Sort

Estável: Não muda a ordem relativa de elementos com valores iguais;
É mais rapido comparado aos outros.

~~~C
void insertionSortSimples(Item *v, int l, int r){
    for(int i = l+1; i <= r; i++){
        for(int j = i; j > l; j--){
            cmpexch(v[j],v[j-1])
        }
    }
}
~~~

~~~C
void insertionSort(int *v, int l, int r){
    for (int i = r; i>l; i--){
        cmpech(v[i-1], v[i])
    }
    for(int i = l+2; i <=r ;i++){
        int j = i;
        Item tmp = v[j];
        while(less(tmp,v[j-1])){
            v[j]=v[j-1];
            j--;
        }
        v[j] = tmp;
    }
}
~~~

## 4. Tabela de comparação

|     Algoritmo    | Complexidade |            |       |
|:----------------:|:------------:|------------|-------|
|                  |    Melhor    |   Médio    | Pior  |
| Insertion sort |     O(n)     | O(n2)      | O(n2) |
| Bubble sort    | O(n)         | O(n2)      | O(n2) |
| Selection sort | O(n2)        | O(n2)      | O(n2) |

[Macro em c](macroEmC.md)

[Retorno](/README.md)
