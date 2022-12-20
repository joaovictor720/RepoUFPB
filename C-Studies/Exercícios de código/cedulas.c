#include <stdio.h>

//código das cédulas

int main(void){
    int quantia;
    int n100, n50, n20, n10, n5, n2, n1;

    printf("Digite sua quantia: \n");
    scanf("%d", &quantia);

    n100 = quantia / 100;
    n50 = (quantia % 100) / 50;
    n20 = ((quantia % 100) % 50) / 20;
    n10 = (((quantia % 100) % 50) % 20) / 10;
    n5 = ((((quantia % 100) % 50) % 20) % 10) / 5;
    n2 = (((((quantia % 100) % 50) % 20) % 10) % 5) / 2;
    n1 = (((((quantia % 100) % 50) % 20) % 10) % 5) % 2;

    printf("Voce precisa de\n %d notas de 100 reais,\n %d de 50 reais,\n %d de 20 reais,\n %d de 10 reais,\n %d de 5 reais,\n %d de 2 reais,\n %d de 1 real", n100, n50, n20, n10, n5, n2, n1);

    return 0;
}
