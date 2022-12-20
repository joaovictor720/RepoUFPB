#include <stdio.h>
#include <math.h>

float lado;

int LadosValidos(float a, float b, float c){
    int cont = 0;

    if (a <= 0){
        cont++;
    }
    if (b <= 0){
        cont++;
    }
    if (c <= 0){
        cont++;
    }
    return cont;
}

float NovoLado(float a, float b, float c){
    if (a <= 0){
        lado = sqrt(c*c - b*b);
    }else if (b <= 0){
        lado = sqrt(c*c - a*a);
    }else if (c <= 0){
        lado = sqrt(a*a + b*b);
    }
    return lado;
}
// espécie de flagger
int EhTrianguloRetangulo(float a, float b, float c){
    switch (LadosValidos(a, b, c)){
        case 0:
        return 'e';
        case 1:
            NovoLado(a, b, c);
            return 0;
        case 2:
            //entrada inválida
            return 1;
    }
}

int main(void){
    float a, b, c;

    printf("Bem vindo ao Verificador e/ou Construtor de Triangulos!\n");
    printf("Insira os catetos, e em seguida a hipotenusa: \n");
    scanf("%f %f %f", &a, &b, &c);

    switch (EhTrianguloRetangulo(a, b, c)){
        case 'e':
            printf("\nEh triangulo retangulo.\n");
            break;
        case 0:
            printf("\nUma entrada invalida\nNovo lado = %.2f\n", lado);
            break;
        default:
            printf("\nEntrada invalida.\n");
    }

    return 0;
}
