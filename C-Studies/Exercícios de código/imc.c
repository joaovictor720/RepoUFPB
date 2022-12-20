#include <stdio.h>

int main(void){
    float imc;
    float peso, altura;

    printf("Insira sua altura: \n");
    scanf("%f", &altura);
    printf("Insira seu peso: \n");
    scanf("%f", &peso);

    imc = peso / (altura * altura);

    printf("Seu IMC/indice de massa corporal: %.2f", imc);

    return 0;
}
