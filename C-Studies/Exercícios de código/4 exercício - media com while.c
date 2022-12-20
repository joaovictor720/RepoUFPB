#include <stdio.h>

int main(void){
    int count = 0, soma = 0, i = 1;
    float media;

    printf("Bota um valor ai:\n");
    while (i != 0){
        scanf("%d", &i);
        soma = soma + i;
        if (i != 0){
            count = count + 1;
        }
        printf("Oto (ou 0 pra parar)\n");
    }
    media = 1.0*soma / count;
    printf("Media deles = %.2f", media);

    return 0;
}
