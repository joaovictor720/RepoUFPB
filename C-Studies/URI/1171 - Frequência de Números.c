#include <stdio.h>

int main(void){
    int contador[2001] = {0}, N, T, i;

    scanf("%d", &N);

    for(i = 0; i < N; i++){
        scanf("%d", &T);
        contador[T]++;
    }
    for(i = 1; i < 2001; i++){
        if(contador[i] > 0){
            printf("%d aparece %d vez(es)\n", i, contador[i]);
        }
    }

    return 0;
}
