#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	int palpite, correto;
	int i;

	srand(time(NULL));
	correto = rand() % 100;

	palpite = -1;
	for (i = 1; i <= 5; i=i+1){
        printf("Tentativa %d\n", i);
        puts("Adivinhe o numero: ");
        scanf("%d", &palpite);

            if (palpite > correto){
                puts("Palpite alto!");
            }else if (palpite < correto){
                puts("Palpite foi baixo!");
            }else if (palpite == correto){
                puts("Voce acertou!");
                return 0;
            }
	}
    puts("Tentativas esgotadas!");

	return 0;
}
