#include <stdio.h>

int main(void){
    int a, b;

    printf("Digite dois valores para comparar: \n");
    scanf("%d", &a);
    scanf("%d", &b);

    if (a == b){
        printf("Os valores sao iguais\n");
    }else{
        if (a > b){
            printf("O menor valor eh %d", b);
        }else{
            printf("O menor valor eh %d", a);
        }
    }

    return 0;
}
