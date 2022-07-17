#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ull unsigned long long
#define Item struct Element
#define key(A) (A.jp)
#define less(a, b) (strcmp(key(a), key(b)) < 0)
#define lessKey(a, k) (strcmp(key(a), k) < 0)
#define eqKey(a, k) (strcmp(key(a), k) == 0)
#define swap(a, b) {Item t = a; a = b;b = t;}
#define cmpswap(a, b){if (less(b, a))swap(a, b)}

struct Element
{
    char jp[81];
    char br[81];
};

int separa(Item *v, int l, int r)
{
    Item pivot = v[r];
    int j = l;
    for (int k = l; k < r; k++)
        if (less(v[k], pivot))
        {
            swap(v[k], v[j]);
            j++;
        }
    swap(v[j], v[r]);
    return j;
}

void quickSort(Item *v, int l, int r)
{
    if (l>=r) return;

    swap(v[(l + r) / 2], v[r - 1]);
    cmpswap(v[l], v[r - 1]);
    cmpswap(v[l], v[r]);
    cmpswap(v[r - 1], v[r]);

    int m = separa(v, l, r);
    quickSort(v, l, m - 1);
    quickSort(v, m + 1, r);
}

void insertionsort(Item *v, int l, int r)
{
    for (int i = l + 1, j; i <= r; i++)
    {
        Item t = v[i];
        for (j = i; j > 0 && less(t, v[j - 1]); j--)
            v[j] = v[j - 1];
        v[j] = t;
    }
}

void qs(Item *v, int l, int r)
{
    quickSort(v, l, r);
    insertionsort(v, l, r);
}

int buscaBinaria(Item *v, int l, int r, char *x)
{
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (eqKey(v[m], x))
            return m;
        else if (lessKey(v[m], x))
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

Item vetor[1000001];

void traduz(){
    int m, n;
    scanf(" %d %d\n", &m, &n);

    for (int i = 0; i < m; i++){
        gets(vetor[i].jp);
        gets(vetor[i].br);
    }

    qs(vetor, 0, m - 1);

    for(int i =0; i<n; i++){
        char linha[81];
        gets(linha);
        char *palavra;
        palavra = strtok(linha, " ");
        while (palavra != NULL)
        {
            int meta = buscaBinaria(vetor, 0, m - 1, palavra);
            if( meta != -1){
                printf("%s ", vetor[meta].br);
            }else{
                printf("%s ", palavra);
            }
            palavra = strtok(NULL, " ");
            printf("%c", " \n"[palavra == NULL]);
        }
    }
    printf("\n");
}

int main(){
    int t;
    scanf(" %d", &t);
    for(int i = 0; i < t; i++)
        traduz();

    return 0;
}
