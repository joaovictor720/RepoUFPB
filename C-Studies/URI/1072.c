#include <stdio.h>

int main(void){
    int out, X, N, i;

    scanf("%d", &N);
    out = N;
    for (i = 0; i < N; i=i+1){
        scanf("%d", &X);
        if (10 <= X && X <= 20){
           out = out - 1;
        }
    }
    printf("%d in\n", N-out);
    printf("%d out\n", out);

    return 0;
}
