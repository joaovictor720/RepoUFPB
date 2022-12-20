#include <stdio.h>

int main(void){
    float diametro;
    float raio, area, perimetro;
    float pi;

    printf("Digite o diametro de um circulo:\n");
    scanf("%f", &diametro);
    printf("As dimensoes desse circulo sao:\n");

    pi = 3.14159;
    raio = diametro / 2;
    area = pi * raio * raio;
    perimetro = 2 * pi * raio;

    printf("Raio = %.2f\n", raio);
    printf("Area = %.2f\n", area);
    printf("Perimetro = %.2f", perimetro);

    return 0;
}
