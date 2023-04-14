#include <stdio.h>

int main() {
    int n, m, p, pa_x = 1, pa_y = 1, pb_x, pb_y, i, dir_a, dir_b;

    scanf("%d %d %d", &n, &m, &p);

    pb_x = n;
    pb_y = m;

    for (i = 1; i <= p; i++) {
        scanf("%d %d", &dir_a, &dir_b);

        if (dir_a == 1) pa_y++;
        else if (dir_a == 2) pa_y--;
        else if (dir_a == 3) pa_x++;
        else if (dir_a == 4) pa_x--;

        if (dir_b == 1) pb_y++;
        else if (dir_b == 2) pb_y--;
        else if (dir_b == 3) pb_x++;
        else if (dir_b == 4) pb_x--;

        if (pa_x < 1 || pa_x > n || pa_y < 1 || pa_y > m) {
            printf("PA saiu na posicao (%d,%d) no passo %d\n", pa_x, pa_y, i);
            return 0;
        }
        else if (pb_x < 1 || pb_x > n || pb_y < 1 || pb_y > m) {
            printf("PB saiu na posicao (%d,%d) no passo %d\n", pb_x, pb_y, i);
            return 0;
        }
        else if (pa_x == pb_x && pa_y == pb_y) {
            printf("Encontraram-se na posicao (%d,%d) no passo %d\n", pa_x, pa_y, i);
            return 0;
        }
    }

    // se nenhum dos casos anteriores ocorreu, os professores não se encontraram
    printf("Nao se encontraram\n");

    return 0;
}
