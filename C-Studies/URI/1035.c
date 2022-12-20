#include <stdio.h>

int main(void){
    int a, b, c, d;
    int div;

    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &d);

    div = a % 2;

    if (b > c && d > a && ((c + d) > (a + b)) && (c > 0 && d > 0) && (div == 0)){
        printf("Valores aceitos\n");
    }else{
        printf("Valores nao aceitos\n");
    }

    return 0;
}
