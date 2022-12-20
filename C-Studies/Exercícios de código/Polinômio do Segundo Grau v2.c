#include <stdio.h>
#include <math.h>

float Delta(float a, float b, float c){
    return (b * b) - (4 * a * c);
}

float Raiz1(float a, float b, float delta){
    return (-b + sqrt(delta)) / (2 * a);
}

float Raiz2(float a, float b, float delta){
    return (-b - sqrt(delta)) / (2 * a);
}

int main(void){
    float a, b, c;
    float delta, x1, x2;

    puts("Insira os coeficientes de um Polinomio do Segundo Grau: ");
    scanf("%f%f%f", &a, &b, &c);
    if (a == 0){
        puts("\nVoce inseriu o coeficiente a = 0, o que anula o grau 2 do polinomio.");
        return 1;
    }

    delta = Delta(a, b, c);
    if (delta >= 0){
            if (delta == 0){
                printf("\nDiscriminante igual a zero. Portanto, x' = x'' = %.1f\n", delta);
            }else{
                x1 = Raiz1(a, b, delta);
                x2 = Raiz2(a, b, delta);

                printf("\nAs raizes sao %.1f e %.1f\n", x1, x2);
        }
    }else{
        puts("\nDiscriminante menor que 0, tornando todas as raizes complexas.");
        return 2;
    }

    return 0;
}
