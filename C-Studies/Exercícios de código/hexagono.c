#include <stdio.h>
#include <math.h>

void CalculaHexagono(float l, float *area, float *perimetro){
    *area = (3*l*l*sqrt(3))/2;
    *perimetro = 6*l;
}

int main(void){
    float l, Area, Perimetro;

    printf("Insira o lado do hexagono: ");
    scanf("%f", &l);

    CalculaHexagono(l, &Area, &Perimetro);
    printf("Area = %.3f\n", Area);
    printf("Perimetro = %.2f\n", Perimetro);

    return 0;
}
