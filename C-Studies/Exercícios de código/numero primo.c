#include <stdio.h>

int main(void){
    int i, n;
    int end;

    puts("Verique se seu numero eh primo:");
    scanf("%d", &n);

    /*o programa encerra aqui pois 1 � considerado
    n�o-primo por conven��o matem�tica*/
    if (n == 1){
        puts("Numero nao-primo");
        puts("Insira qualquer coisa para fechar o programa.");
        scanf("%d", &end);
        return 0;
    }
    //o programa testa todos os naturais at� chegar no valor inputado
    //se em nenhum desses testes o resto for 0, o n�mero � primo
    for (i = 2; i < n; i=i+1){
        if (n % i == 0){
            puts("Numero nao-primo");
            puts("Insira qualquer coisa para fechar o programa.");
            scanf("%d", &end);
            return 0;
        }
    }
    puts("Numero primo");

    puts("Insira qualquer coisa para fechar o programa.");
    scanf("%d", &end);
    return 0;
}
