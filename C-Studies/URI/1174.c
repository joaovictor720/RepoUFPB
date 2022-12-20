#include <stdio.h>

#define SIZE_AR 10

int main(void){
    int i;
    float A[SIZE_AR];

    for (i = 0; i < SIZE_AR; i++){
        scanf("%f", &A[i]);
        if (A[i] <= 10){
            printf("A[%d] = %.1f\n", i, A[i]);
        }
    }

    return 0;
}
