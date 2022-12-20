#include <stdio.h>

int main(void){
    unsigned long long a1, an, soma;

    scanf("%llu%llu", &a1, &an);

    soma = ((an - a1 + 1) * (a1 + an)) / 2;
    printf("%llu\n", soma);

    return 0;
}
