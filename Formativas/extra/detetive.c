#include <stdio.h>

#define MAX_PISTAS 5000

typedef struct {
    int id;
    int valor;
    int prox_id;
} Pista;

int main() {
    int n, i, j;
    Pista pistas[MAX_PISTAS];
    int ordem[MAX_PISTAS];

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d %d %d", &pistas[i].id, &pistas[i].valor, &pistas[i].prox_id);
    }
    ordem[0] = 0;
    for (i = 1; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (pistas[j].id == pistas[ordem[i-1]].prox_id) {
                ordem[i] = j;
                break;
            }
        }
    }
    for (i = 0; i < n; i++) {
        printf("%d\n", pistas[ordem[i]].valor);
    }
    return 0;
}
