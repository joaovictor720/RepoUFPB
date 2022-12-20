#include <stdio.h>

double AdicioneNaMedia(double valor){
    static double soma = 0, cont = 0;
    cont++;
    soma += valor;
    return soma / cont;
}

int main(void){
    int i, qtd;
    double valor, media;

    printf("Quantidade de valores inseridos: ");
    scanf("%d", &qtd);

    for (i = 0; i < qtd; i++){
        printf("Valor: \n");
        scanf("%lf", &valor);
        media = AdicioneNaMedia(valor);
        printf("Media: %.2lf\n", media);
    }

    return 0;
}
