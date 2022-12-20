#include <stdio.h>

int main(void){
    long long unsigned P;

    while (1){
        scanf("%llu", &P);
        if (!P){
            puts("0");
            continue;
        }
        if (P == -1){
            return 0;
        }
        printf("%llu\n", P-1);
    }

    return 0;
}
