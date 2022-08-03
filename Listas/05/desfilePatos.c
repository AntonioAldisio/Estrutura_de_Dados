#include <stdio.h>

conta_patos(n){

    int count = 0;
    int anterior = 0;
    int x;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (count == 0){
            anterior = x;
            count++;
        }
        else{
            if(anterior == x){
                count++;
            }
            else{
                count += -1;
            }
        }
    }
    printf("%d\n", anterior);

}


int main(){
    int n; // numero de patos observados
    for(;;){
        scanf("%d", &n);
        if (n == 0) return 0;
        conta_patos(n);
    }

}
