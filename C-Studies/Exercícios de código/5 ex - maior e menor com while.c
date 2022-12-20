#include <stdio.h>

int main(void){
    int maior, menor, v;

    scanf("%d", &v);
    maior = v;
    menor = v;

    while (v != 0){
        scanf("%d", &v);
        if (v > maior){
            maior = v;
        }else if (v < menor && (v != 0)){
            menor = v;
        }
    }
    printf("\nO maior valor foi %d\n", maior);
    printf("O menor valor foi %d\n", menor);

    return 0;
}
