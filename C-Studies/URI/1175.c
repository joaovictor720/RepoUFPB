#include <stdio.h>

#define SIZE_AR 20

int main(void){
    int N[SIZE_AR], i, aux;

    for (i = 0; i < SIZE_AR; i++){
        scanf("%d", &N[i]);
    }
    for (i = 0; i < SIZE_AR / 2; i++){
        aux = N[i];
        N[i] = N[SIZE_AR - 1 - i];
        N[SIZE_AR - 1 - i] = aux;
    }
    for (i = 0; i < SIZE_AR; i++){
        printf("N[%d] = %d\n", i, N[i]);
    }

    return 0;
}
