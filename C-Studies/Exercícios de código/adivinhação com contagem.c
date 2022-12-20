#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	int palpite, correto;
	int i;

	srand(time(NULL));
	correto = rand() % 100;

    i = 0;
	palpite = -1;
	while (palpite != correto) {
        printf("Adivinhe o numero: ");
        scanf("%d", &palpite);

            if (palpite > correto){
                puts("Palpite alto!");
            }else if (palpite < correto){
                puts("Palpite foi baixo!");
            }
        i = i + 1;
	}

    puts("Voce acertou!");
    printf("Voce tentou %d vezes!\n", i);
	return 0;
}
