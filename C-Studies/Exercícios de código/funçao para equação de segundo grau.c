#include <stdio.h>
#include <math.h>

int ResolveEquacao2Grau(float a, float b, float c, float *x1, float *x2){
    float delta;

    if (a == 0){
        return -1;
    }
    delta = b*b - 4*a*c;
    if (delta < 0){
        return -2;
    }
    *x1 = (-b + sqrt(delta)) / (2 * a);
    *x2 = (-b - sqrt(delta)) / (2 * a);

    return 0;
}

int main(void){
    float a, b, c;
    float x1, x2;

    puts("Insira os coeficientes da equacao do segundo grau:");
    scanf("%f%f%f", &a, &b, &c);

    switch (ResolveEquacao2Grau(a, b, c, &x1, &x2)){
        case 0:
            printf("Raizes sao %.2f e %.2f\n", x1, x2);
            break;
        case -1:
            puts("Coeficientes nao representam uma equaçao do segundo grau.");
            break;
        case -2:
            puts("Raizes complexas.");
            break;
    }

    return 0;
}
