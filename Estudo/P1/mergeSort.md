# MergeSort

Desvantagem

- Memoria adicional para criar o vetor auxiliar.

~~~C
// Premissa: Vetores V1 e V2 ordernados
Item *merge (Item *a, int la, int ra, Item *b int lb, int rb){
    int tamanhoA = (ra - la + 1);
    int tamanhoB = (rb - lb + 1);

    Item *c = malloc(sizeof(Item)*(tamanhoA+tamanhoB));
    int lc = 0;
    int rc = (tamanhoA+tamanhoB -1);
    int ia = la;
    int ib = lb;
    int ic = 0;

    while(ia < ra && ib <= rb){
        if(lesseq(a[ia],b[ib])){
            c[ic] = a[ia];
            ic++;
            ia++;
        }else{
            c[ic] = b[ib];
            ic++;
            ib++;
        }
    }
    while(ia<= ra){
        c[ic] = a[ia];
        ia++;
    }
    while(ib <= rb){
        c[ic] = a[ib];
        ib++;
    }
    return c;
}
~~~

~~~C
void mergeSort (Item *v, int l, int r){
    if(l => r) return;

    int meio = (l+r)+l/2;
    mergeSort (v,l, meio);
    mergeSort (v,meio+1,r);

    Item *c = merge(v,l,meio, v, meio+1, r);
    for(int i = 0; i < r-l+1; i++){
        v[l] = c[i];
        l++;
    }
    free(c);
}
~~~

[Retorno](/README.md)
