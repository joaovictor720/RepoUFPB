#include <stdio.h>

int main(void){
    int N, produto = 1;

    scanf("%d", &N);

    while (N >= 1){
        produto = produto * N--;
    }
    printf("%d\n", produto);

    return 0;
}
