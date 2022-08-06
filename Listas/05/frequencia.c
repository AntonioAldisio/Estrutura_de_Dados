#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define min(a, b) (a < b ? a : b)
#define max(a, b) (b < a ? a : b)
#define key(x) (x)
#define less(a, b) (a.frequencia == b.frequencia ? a.num_ascii < b.num_ascii : a.frequencia < b.frequencia)
#define swap(a, b) { Lista t = a; a = b; b = t; }
#define cmpswap(a, b){ if(less(a, b)) swap(a, b); }



typedef struct Lista{
    int num_ascii; // k
    int frequencia; // v
}Lista;

struct Lista vetor[130];

int partition(Lista *v, int l, int r)
{
    Lista pivot = v[r];
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

void quicksortM3(Lista *v, int l, int r)
{
    if (r - l <= 32)
        return;

    swap(v[(l + r) / 2], v[r - 1]);
    cmpswap(v[l], v[r - 1]);
    cmpswap(v[l], v[r]);
    cmpswap(v[r - 1], v[r]);

    int m = partition(v, l, r);
    quicksortM3(v, l, m - 1);
    quicksortM3(v, m + 1, r);
}

void insertionsort(Lista *v, int l, int r)
{
    for (int i = l + 1, j; i <= r; i++)
    {
        Lista t = v[i];
        for (j = i; j > 0 && less(t, v[j - 1]); j--)
            v[j] = v[j - 1];
        v[j] = t;
    }
}

void quicksort(Lista *v, int l, int r)
{
    quicksortM3(v, l, r);
    insertionsort(v, l, r);
}

// merge(struct Lista *v, int l, int r1, int r2){
//     struct Lista *v2=malloc(sizeof(Lista)*(r2-l+1));
//     int k = 0;
//     int i = l;
//     int j = r1 + 1;
//     while(i <= r1 && j <= r2){
//         if(v[i].frequencia < v[j].frequencia){
//             v2[k++] = v[i++];
//         }else{
//             v2[k++] = v[j++];
//         }
//     }
//     while(i <= r1) v2[k++] = v[i++];
//     while(j <= r2) v2[k++] = v[j++];
//     k=0;
//     for(i = l; i <= r2; i++){
//         v[i] = v2 [k++];
//     }
//     free(v2);
// }

// mergeSort(struct Lista *v, int l, int r){
//     if (l >= r) return 0;
//     int meio = (l + r)/2;
//     mergeSort(v, l, meio);
//     mergeSort(v, meio+1, r);
//     merge(v, l, meio, r);
// }




int ascii(char *str){
    int sum[130];
    int i = 0;

    for(int i = 0; i < 130; i++){
        sum[i] = 0;
    }

    for(int i = 0; str[i] != '\0'; i++){
        sum[str[i]]++;
    }

    int tamanho = 0;
    for(int i = 0; i < 130; i++){
        if(sum[i]){
            vetor[tamanho].num_ascii = i;
            vetor[tamanho].frequencia = sum[i];
            tamanho++;
        }
    }
    return tamanho;
}



int main(){
    char s[1010];
    int tamanho;
    int ultimo;
    while (scanf(" %s", s) == 1){
        tamanho = ascii(s);

        quicksort(vetor, 0, tamanho-1);

        for(int i = 0; i < tamanho; i++){
            printf("%d %d\n", vetor[i].num_ascii, vetor[i].frequencia);
        }
        printf("\n");
    }

    return 0;
}