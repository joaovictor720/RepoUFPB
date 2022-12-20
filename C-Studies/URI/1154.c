#include <stdio.h>

int main(void){
    int idade, soma = 0, i = 0;
    float media;

    scanf("%d", &idade);

    while (idade >= 0){
        soma = soma + idade;
        i = i + 1;
        scanf("%d", &idade);
    }
    media = 1.0*soma / i;
    printf("%.2f\n", media);

    return 0;
}
