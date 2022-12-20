/*
 ============================================================================
 Name        : areaCirculo.c
 Author      : lincoln
 Version     :
 Copyright   : Your copyright notice
 Description : Exemplo de um programa que calcula a area de um circulo de
 			   raio 5.
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int cte,raio;
    float area;

    printf("Bem-vindo, \n");
    scanf("%d", &raio);
    scanf("%d", &cte);

    area = cte * raio*raio;

    printf("Para r = %d, a = %f\n", raio, area);

    return 0;
}
