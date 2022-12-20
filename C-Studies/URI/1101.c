#include <stdio.h>

int main(void){
    int M = 1, N = 1, sum;

    scanf("%d %d", &M, &N);

    while (M > 0 && N > 0){
        sum = 0;
        if (M > N){
            while (M >= N){
                printf("%d ", N);
                sum = sum + N;
                N = N + 1;
            }
        }else{
            while (M <= N){
                printf("%d ", M);
                sum = sum + M;
                M = M + 1;
            }
        }
        printf("Sum=%d\n", sum);
        scanf("%d %d", &M, &N);
    }

    return 0;
}
