#include <stdio.h>

int main(void){
    int i;
    int s, min, h, d, m;
    int resto;

    printf("Sua idade: ");
    scanf("%d", &i);

    /*cada fator além do i representa as parcelas de tempo comuns, como dias, meses, etc*/
    m = i * 12;
    printf("\nVoce ja viveu pelo menos %d meses,", m);
    d = i * 12 * 30;
    printf("\nOu %d dias,", d);
    h = i * 12 * 30 * 24;
    printf("\nOu %d horas,", h);
    min = i * 12 * 30 * 24 * 60;
    printf("\nOu %d minutos,", min);
    s = i * 12 * 30 * 24 * 60 * 60;
    printf("\nOu %d segundos.\n", s);

    return 0;
}
