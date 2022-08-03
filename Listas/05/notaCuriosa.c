#include <stdio.h>
#include <stdlib.h>

int v[1010];

int count(int n){
    int x;
    int ans = 0, melhor = 0;
    for (int i = 0; i < n; i++){
        scanf(" %d",&x);
        if (++v[x] > melhor){
            melhor = v[x];
            ans = x;
        }
        else if (v[x] == melhor && ans < x)
            ans = x;
    }
    return ans;
}

int main(){
    int n;
    scanf(" %d", &n);

    printf("%d\n", count(n));

    return 0;
}

