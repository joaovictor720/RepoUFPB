#include <stdio.h>

int main(void){
    int X, N, i, j, soma;

    scanf("%d", &X);

    for (i = 1; i <= X; i++){
        scanf("%d", &N);

        soma = 0;
        for (j = 1; j < N; j++){
            if (N % j == 0){
                soma += j;
            }
        }
        if (soma == N){
            printf("%d eh perfeito\n", N);
        }else{
            printf("%d nao eh perfeito\n", N);
        }
    }

    return 0;
}
