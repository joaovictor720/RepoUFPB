#include <stdio.h>

//código das cédulas

int main(void){
    int quantia;
    int n, resto;

    printf("Digite sua quantia: \n");
    scanf("%d", &quantia);

    n = quantia / 100;
    resto = quantia % 100;
    printf("\n%d notas de 100", n);

    quantia = resto;
    n = quantia / 50;
    resto = quantia % 50;
    printf("\n%d notas de 50", n);

    quantia = resto;
    n = quantia / 20;
    resto = quantia % 20;
    printf("\n%d notas de 20", n);

    quantia = resto;
    n = quantia / 10;
    resto = quantia % 10;
    printf("\n%d notas de 10", n);

    quantia = resto;
    n = quantia / 5;
    resto = quantia % 5;
    printf("\n%d notas de 5", n);

    quantia = resto;
    n = quantia / 2;
    resto = quantia % 2;
    printf("\n%d notas de 2", n);

    quantia = resto;
    n = quantia / 1;
    resto = quantia % 1;
    printf("\n%d notas de 1\n", n);

    return 0;
}
