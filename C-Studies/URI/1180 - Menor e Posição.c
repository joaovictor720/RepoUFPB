#include <stdio.h>

void MenorValor(int X[], int size, int *pos, int *minValor){
    int i, menor = 100000;

    for (i = 0; i < size; i++){
        if (X[i] < menor){
            menor = X[i];
            *minValor = X[i];
            *pos = i;
        }
    }
}

int main(void){
    int size, pos, minValor, i;

    scanf("%d", &size);
    int X[size];

    for (i = 0; i < size; i++){
        scanf("%d", &X[i]);
    }
    MenorValor(X, size, &pos, &minValor);
    printf("Menor valor: %d\n", minValor);
    printf("Posicao: %d\n", pos);

    return 0;
}
