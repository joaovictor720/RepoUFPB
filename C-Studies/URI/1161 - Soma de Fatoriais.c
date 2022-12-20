#include <stdio.h>

unsigned long long Fatorial(int x){
    unsigned long long produto = 1, i;
    i = x;
    while (i--){
        produto *= x--;
    }
    return produto;
}

int main(void){
    int M, N;
    unsigned long long soma;

    while (scanf("%d %d", &M, &N) != EOF){
        soma = Fatorial(M) + Fatorial(N);
        printf("%llu\n", soma);
    }

    return 0;
}
