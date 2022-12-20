#include <stdio.h>

int main(void)
{
    float largura, altura;
    float volume;
    float rendimento, area;
    float qtd;

    printf("Largura da parede: ");
    scanf("%f", &largura);

    printf("Altura da parede: ");
    scanf("%f", &altura);

    printf("Rendimento de cada litro da tinta: ");
    scanf("%f", &rendimento);

    printf("Volume de cada lata: ");
    scanf("%f", &volume);

    area = largura * altura;
    qtd = area / (rendimento * volume);
    printf("Voce precisa de %1.2f latas", qtd);

    return 0;
}
