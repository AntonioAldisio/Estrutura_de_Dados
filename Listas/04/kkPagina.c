#include<stdio.h>
#include<stdlib.h>

#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { int t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

int separa(int *V,int l,int r){
  int c=V[r];
  int j=l;
  int aux;
  for(int k=l;k<r;k++)
    if(less(V[k],c)){
        exch(V[k],V[j]);
      j++;
    }
    exch(V[j],V[r]);
  return j;
}

void quicksort(int *V,int l, int r){
  if (r<=l) return;
    // Mediana de 3
    cmpexch(V[(l+r)/2],V[r]);
    cmpexch(V[l],V[(l+r)/2]);
    cmpexch(V[r],V[(l+r)/2]);
    // Fim da mediana de 3
    int j=separa(V,l,r);
    quicksort(V,l,j-1);
    quicksort(V,j+1,r);
}


void quickselect(int *v,int l, int r, int k){
    int i;
    i= separa(v,l,r);
    if(r<=l)return;
    if(i>k)quickselect(v,l,i-1,k);
    if(i<k)quickselect(v,i+1,r,k);
}


int main(){
    int n,p,x;
    int *vetor;
    scanf("%d %d %d", &n, &p, &x);
    vetor = malloc (sizeof(int)*n);
    for(int i=0; i<n; i++){
        scanf("%d", &vetor[i]);
    }
    int iniciop =x*p;

    quickselect(vetor,0,n-1,iniciop);
    quickselect(vetor,iniciop+1,n-1,iniciop+x-1);
    quicksort(vetor,iniciop,iniciop+x-1);

    for(int j=iniciop; j<=iniciop+x-1; j++){
        printf("%d\n", vetor[j]);
    }
    return 0;
}
