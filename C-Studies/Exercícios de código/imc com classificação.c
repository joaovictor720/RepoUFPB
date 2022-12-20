#include <stdio.h>
#include <math.h>

int main(void){
    float p, h, imc;

    printf("Insira seu peso:\n");
    scanf("%f", &p);
    printf("Insira sua altura:\n");
    scanf("%f", &h);

    imc = p / (pow(h, 2));
    printf("\nSeu IMC = %.2f", imc);

    if (imc <= 18.5){
        printf("\nVoce tem um IMC do tipo Baixo Peso\n");
    }else if (imc <= 25){
        printf("\nVoce tem um IMC do tipo Normal\n");
    }else if (imc <= 30){
        printf("\nVoce tem um IMC do tipo Sobrepeso\n");
    }else{
        printf("\nVoce tem um IMC do tipo de Obeso\n");
    }

    return 0;
}
