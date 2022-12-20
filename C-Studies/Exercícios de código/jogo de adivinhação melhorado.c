#include <stdio.h>

int main(void){
    int palpite;

    puts("Bem-vindo!");
    puts("Adivinhe o numero:");
    scanf("%d", &palpite);

    while (palpite != 5){
        puts("\nVoce perdeu.");
        if (palpite > 5){
            puts("Seu palpite foi alto.");
        }else{
            puts("Seu palpite foi baixo.");
        }
        puts("Adivinhe o numero:");
        scanf("%d", &palpite);
    }
    puts("Voce ganhou!");

    return 0;
}
