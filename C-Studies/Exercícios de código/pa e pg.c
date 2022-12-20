#include <stdio.h>

int main(void){
    char tipo;
    float t1, r, n;
    float soma = 0, i;

    puts("Tipo da progressao (digite a inicial):");
    scanf("%c", &tipo);
    puts("Termo inicial:");
    scanf("%f", &t1);
    puts("Razao:");
    scanf("%f", &r);
    puts("Tamanho:");
    scanf("%f", &n);

    if ((tipo == 'a') || (tipo == 'A')){
        for (i = 1; i <= n; i=i+1){
            printf("%.1f\n", t1);
            soma = soma + t1;
            t1 = t1 + r;
        }
    }
    if ((tipo == 'g') || (tipo == 'G')){
        for (i = 1; i <= n; i=i+1){
            printf("%.3f\n", t1);
            soma = soma + t1;
            t1 = t1 * r;
        }
    }
    printf("\nSoma = %.3f", soma);

    return 0;
}
