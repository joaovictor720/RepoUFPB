#include <stdio.h>

int main(void){
    int senha;

    scanf("%d", &senha);

    while (senha != 2002){
        puts("Senha Invalida");
        scanf("%d", &senha);
    }

    puts("Acesso Permitido");
    return 0;
}
