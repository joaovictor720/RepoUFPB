#include <stdio.h>

int main(void){
    float area;
    int b, h;

    printf("Insira a base do triangulo: ");
    scanf("%d", &b);
    printf("\nInsira a altura do triangulo: ");
    scanf("%d", &h);

    area = b * h / 2.0;
    printf("\nArea do triangulo: %.2f", area);

    return 0;
}
