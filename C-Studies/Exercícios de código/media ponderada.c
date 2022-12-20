#include <stdio.h>

int main(void){
    float p1, p2, p3, p4;
    float m1, m2, m3, m4;
    float media;

    printf("Insira a primeira media: \n");
    scanf("%f", &m1);
    printf("Insira a segunda media: \n");
    scanf("%f", &m2);
    printf("Insira a terceira media: \n");
    scanf("%f", &m3);
    printf("Insira a quarta media: \n");
    scanf("%f", &m4);

    p1 = 1;
    p2 = 2;
    p3 = 3;
    p4 = 4;

    media = ((m1 * p1) + (m2 * p2) + (m3 * p3) + (m4 * p4)) / (p1 + p2 + p3 + p4);
    printf("\nSua media final: %.2f\n", media);

    return 0;
}
