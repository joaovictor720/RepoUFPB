#include <stdio.h>

int SizeStr(const char str[]){
    int cont = 0, i = 0;

    while (str[i] != '\0'){
        i++;
        cont++;
    }
    return cont;
}

int main(void){
    char str1[] = "opa";
    char *str2 = "falae";
    int tam;

    tam = SizeStr(str1);
    printf("%d\n", tam);

    return 0;
}
