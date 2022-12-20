#include <stdio.h>

int main(void){
    float a, b;

    printf("Digite dois valores para identificar o menor: \n");
    scanf("%f", &a);
    scanf("%f", &b);

    if (a > b){
        printf("%.2f", b);
    }else{
        printf("%.2f", a);
    }

    return 0;
}
