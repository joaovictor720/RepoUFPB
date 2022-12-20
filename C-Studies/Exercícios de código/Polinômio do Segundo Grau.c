#include <stdio.h>
#include <math.h>

int main(void){
    float a, b, c;
    float delta, x1, x2;

    puts("Insira os coeficientes, respectivamente, para o a, b e c: ");
    scanf("%f", &a);
    if (a == 0){
        puts("Voce inseriu o coeficiente a=0, o que anula o grau 2 de sua funcao.");
        return 1;
    }
    scanf("%f", &b);
    scanf("%f", &c);

    delta = (b * b) - (4 * a * c);
    if (delta >= 0){
            if (delta == 0){
                printf("Discriminante igual a zero. Portanto, x' = x'' = %.1f", delta);
            }else{
                x1 = (-b + sqrt(delta)) / (2 * a);
                x2 = (-b - sqrt(delta)) / (2 * a);
                printf("As raizes sao %.1f e %.1f", x1, x2);
        }
    }else{
        puts("\nDiscriminante menor que 0, tornando todas as raizes complexas.");
        return 2;
    }

    return 0;
}
