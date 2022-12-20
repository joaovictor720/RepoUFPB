#include <stdio.h>

int main(void){
    int i, N[10], v;

    scanf("%d", &N[0]);

    printf("N[0] = %d\n", N[0]);
    for (i = 1; i < 10; i++){
        N[i] = 2*N[i-1];
        printf("N[%d] = %d\n", i, N[i]);
    }

    return 0;
}
