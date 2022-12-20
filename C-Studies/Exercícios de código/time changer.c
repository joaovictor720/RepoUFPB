#include <stdio.h>

int main(void){
    int t, s;
    float h, m;
    printf("Tempo em segundos a ser mudado: \n");
    scanf("%d", &t);

    s = t;
    m = t / 60.0;
    h = m / 60.0;

    printf("\nO tempo em horas eh: %.2f\n", h);
    printf("O tempo em minutos eh: %.2f\n", m);
    printf("O tempo em segundos eh: %d", s);

    return 0;
}
