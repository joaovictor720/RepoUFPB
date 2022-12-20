#include <stdio.h>

int main(void){
    int t, s, h, m;
    int resto;
    int end;

    printf("Tempo, em segundos, a ser dividido: ");
    scanf("%d", &t);

    h = t / 3600;
    resto = t % 3600;
    m = resto / 60;
    t = resto % 60;
    s = t;

    printf("\nDe forma mais resumida, o tempo representa %dh %dmin %ds.\n", h, m, s);

    return 0;
}
