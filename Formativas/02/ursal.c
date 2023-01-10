#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ull unsigned long long
#define less(a, b) (a.value == b.value ? a.key > b.key : a.value > b.value)
#define swap(a, b) { Item t = a; a = b; b = t; }
#define cmpswap(a,b) { if (less(b,a)) swap(a,b); }

typedef struct {
    int key;
    int value;
} Item;


int partition(Item *v, int l, int r)
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

void quicksort(Item *v, int l, int r)
{
    if (r <= l)
        return;

    cmpswap(v[(l + r) / 2], v[r]);
    cmpswap(v[l], v[(l + r) / 2]);
    cmpswap(v[r], v[(l + r) / 2]);

    int m = partition(v, l, r);
    quicksort(v, l, m - 1);
    quicksort(v, m + 1, r);
}



Item presidete[91];
Item senadores[901];
Item deputadosFederal[9001];
Item deputadosEstadutal[90001];
int sizePresidente = 0, sizeSenador = 0, sizeDepFed = 0, sizeDepEst = 0;

int main(){

    long long vagasSenador, vagasDepFed, vagasDepEst;
    long long votos_presidente = 0;
    long long voto_invalido = 0;
    long long voto_validoTotal = 0;

    scanf(" %lld %lld %lld", &vagasSenador, &vagasDepFed, &vagasDepEst);

    int voto, qtd_digito;
    while(scanf("%d%n", &voto, &qtd_digito)!= EOF){
        if(voto < 0){
            voto_invalido++;
            continue;
        }
        // Presidente
        if((qtd_digito - 1) == 2 && voto > 0){
            presidete[voto - 10].key = voto;
            presidete[voto - 10].value++;
            votos_presidente++;

        }
        // Senador
        if((qtd_digito - 1) == 3 && voto > 0 ){
            senadores[voto - 100].key = voto;
            senadores[voto - 100].value++;
        }
        // Deputado Federal
        if((qtd_digito - 1) == 4 && voto > 0){
            deputadosFederal[voto - 1000].key = voto;
            deputadosFederal[voto - 1000].value++;
        }
        // Deputado Estadual
        if((qtd_digito - 1) == 5 && voto > 0){
            deputadosEstadutal[voto - 10000].key = voto;
            deputadosEstadutal[voto - 10000].value++;
        }
        voto_validoTotal++;
    }


    for(int i = 0; i < 91; i++){
        if(presidete[i].value){
            presidete[sizePresidente] = presidete[i];
            sizePresidente++;
        }
    }

    int votos_senador = 0;
    for(int i = 0; i < 901; i++){
        if(senadores[i].value){
            senadores[sizeSenador] = senadores[i];
            sizeSenador++;
        }
    }

    int votos_dep_fed = 0;
    for(int i = 0; i < 9001; i++){
        if(deputadosFederal[i].value){
            deputadosFederal[sizeDepFed] = deputadosFederal[i];
            sizeDepFed++;
        }
    }

    int votos_dep_est = 0;
    for(int i = 0; i < 90001; i++){
        if(deputadosEstadutal[i].value){
            deputadosEstadutal[sizeDepEst] = deputadosEstadutal[i];
            sizeDepEst++;
        }
    }

    printf("%lld %lld\n", voto_validoTotal, voto_invalido);

    quicksort(presidete, 0, sizePresidente - 1);
    quicksort(senadores, 0, sizeSenador - 1);
    quicksort(deputadosFederal, 0, sizeDepFed - 1);
    quicksort(deputadosEstadutal, 0, sizeDepEst - 1);

    if((double)presidete[0].value / votos_presidente >= .51)
        printf("%d\n", presidete[0].key);
    else
        printf("Segundo turno\n");

    for(int i = 0; i < vagasSenador; i++)
        printf("%d ", senadores[i].key);
    printf("\n");

    for(int i = 0; i < vagasDepFed; i++)
        printf("%d ", deputadosFederal[i].key);
    printf("\n");

    for(int i = 0; i < vagasDepEst; i++)
        printf("%d ", deputadosEstadutal[i].key);
    printf("\n");
    return 0;
}

