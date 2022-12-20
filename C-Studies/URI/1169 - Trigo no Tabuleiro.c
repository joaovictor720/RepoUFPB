#include <stdio.h>

//contador de todos os grãos do tabuleiro
unsigned long long Graos(unsigned long long casa[], int size){
    unsigned long long i, soma = 1;

    for (i = 1; i < size; i++){
        casa[i] = 2*casa[i-1];
        soma += casa[i];
    }
    return soma;
}

int main(void){
    int t, n, i;

    scanf("%d", &t);

    for (i = 0; i < t; i++){
        scanf("%d", &n);
        unsigned long long casa[n];
        casa[0] = 1;

        printf("%llu kg\n", Graos(casa, n) / (12 * 1000) );
    }

    return 0;
}
