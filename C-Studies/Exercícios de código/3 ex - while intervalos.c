#include <stdio.h>

int main(void){
    int i1, i2;

    printf("Insira os extremos de um intervalo inteiro:\n");
    scanf("%d%d", &i1, &i2);
    printf("Os elementos do intervalo sao:\n");

    if (i1 > i2){
        while (i1 >= i2){
            printf("%d\n", i2);
            i2 = i2 + 1;
        }
    }else{
        while (i1 <= i2){
            printf("%d\n", i1);
            i1 = i1 + 1;
        }
    }

    return 0;
}
