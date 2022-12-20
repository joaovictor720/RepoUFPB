#include <stdio.h>
#include <string.h>

char Validador(const char *senha){
    int i, numero = 0, maiuscula = 0, minuscula = 0;

    //v� se a senha tem tamanho adequado
    if (strlen(senha) < 6 || 32 < strlen(senha)){
        return 'i';
    }

    /*vai fazer cada caractere passar por uma s�rie de testes*/
    for (i = 0; senha[i] != '\0'; i++){
        //limites de intervalo de acordo com a tabela ASCII
        if ('0' <= senha[i] && senha[i] <= '9'){
            numero = 1; //v� se o caractere � um n�mero
            continue;
        }else if ('A' <= senha[i] && senha[i] <= 'Z'){
            maiuscula = 1; //v� se o caractere � uma letra mai�scula
            continue;
        }else if ('a' <= senha[i] && senha[i] <= 'z'){
            minuscula = 1; //v� se o caractere � uma letra min�scula
            continue;
        }else{
            return 'i'; //sendo qualquer outra coisa, � senha inv�lida
        }
    }

    /*se n�o tiver pelo menos um caractere de cada
    *tipo abaixo, ent�o a senha � inv�lida*/
    if (numero && maiuscula && minuscula){
        return 'v';
    }else{
        return 'i';
    }
}

void RemoveNL(char *str){
    str[strlen(str) - 1] = '\0';
}

int main(void){
    char senha[1002];

    while (fgets(senha, 1002, stdin) != NULL){
        RemoveNL(senha); //tira o \n do fgets
        switch (Validador(senha)){
            case 'v':
                puts("Senha valida.");
                break;
            case 'i':
                puts("Senha invalida.");
        }
    }

    return 0;
}
