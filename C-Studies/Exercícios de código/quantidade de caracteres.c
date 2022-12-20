#include <stdio.h>

int SizeStr(const char str[]){
    int cont = 0, i = 0;

    while (str[i] != '\0'){
        i++;
        cont++;
    }
    return cont;
}

int ContaChar(const char *str, char procura){
    int i, cont = 0;

    for (i = 0; str[i] != '\0'; i++){
        if (str[i] == procura){
            cont++;
        }
    }
    return cont;
}

int ContaPalavras(const char *str){
    int i, cont = 0;

    for (i = 0; str[i] != '\0'; i++){
        if (str[i] == ' '){
            cont++;
        }
    }

    /*o contador recebe incremento pois
    *a função conta o número de espaços entre
    *palavras, e não o número de palavras*/
    return cont+1;
}

int main(void){
    char str1[] = "opa";
    char *str2 = "init";
    int size;

    size = SizeStr(str1);
    printf("tamanho de \"%s\" = %d\n", str1, size);

    printf("i em \"%s\" = %d\n", str2, ContaChar(str2, 'i'));

    str2 = "eu sou o batman";
    printf("palavras em \"%s\" = %d\n", str2, ContaPalavras(str2));

    str2 = "oi, eu sou o goku.";
    printf("palavras em \"%s\" = %d\n", str2, ContaPalavras(str2));

    return 0;
}
