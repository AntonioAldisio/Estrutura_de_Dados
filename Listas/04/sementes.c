#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define lessValues(a, b) (a.value == b.value ? a.key < b.key : a.value < b.value)
#define lessKey(a, b) (a.key == b.key ? a.value < b.value : a.key < b.key)
#define swap(a, b){ int t; t=a;a=b;b=t; }
#define cmpswapValue(a, b) { if (lessValues(b,a)) swap(a,b); }
#define cmpswapKey(a, b) { if (lessKey(b,a)) swap(a,b); }

struct Elemento{
    long long key;
    int value;
};


int separaValues(int *v, int l, int r){
    int pivot = v[r];
    int j = l;
    for (int k = l; k < r; k++)
        if (lessValues(v[k], pivot))
        {
            swap(v[k], v[j]);
            j++;
        }
    swap(v[j], v[r]);
    return j;
}


void quicksortValues(int *v, int l, int r)
{
    if (r - l <= 32)return;

    swap(v[(l + r) / 2], v[r - 1]);
    cmpswapValue(v[l], v[r - 1]);
    cmpswapValue(v[l], v[r]);
    cmpswapValue(v[r - 1], v[r]);

    int m = separaValues(v, l, r);
    quicksort(v, l, m - 1);
    quicksort(v, m + 1, r);
}


int separaKeys(int *v, int l, int r){
    int pivot = v[r];
    int j = l;
    for (int k = l; k < r; k++)
        if (lessKey(v[k], pivot))
        {
            swap(v[k], v[j]);
            j++;
        }
    swap(v[j], v[r]);
    return j;
}


void quicksortValues(int *v, int l, int r)
{
    if (r - l <= 32)return;

    swap(v[(l + r) / 2], v[r - 1]);
    cmpswapKey(v[l], v[r - 1]);
    cmpswapKey(v[l], v[r]);
    cmpswapKey(v[r - 1], v[r]);

    int m = separaKeys(v, l, r);
    quicksort(v, l, m - 1);
    quicksort(v, m + 1, r);
}

int v[1000001];


void print(int *v, int n){
    for(int i = 0; i<n; i++)
        printf("%lld %d\n", v[i].key, v[i].value);
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; scanf(" %lld %d", &v[i].key, &v[i].value) ==2; i++);

    quicksortValues(v, i-1, n-1);
    quicksortKeys(v, 0, n-1);

    print(v, n);

    return 0;
}