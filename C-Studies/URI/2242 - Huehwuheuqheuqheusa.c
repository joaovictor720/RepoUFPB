#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void CopiaVogais(const char *str1, char *str2){
    int i;
    for (i = 0; str1[i] != '\0'; i++){

        if ( (str1[i] == 'a') || (str1[i] == 'b') || (str1[i] == 'i') || (str1[i] == 'o') || (str1[i] == 'u') ){
            str2[i] = str1[i];
            printf("str1[%d] : %c\n", i, str1[i]);
            printf("str2[%d] : %c\n", i, str2[i]);
        }
        //if (str1[i+1] == '\0'){
            //str2[i] = '\0';
        //}
        if (str2[i] == '\0'){
            printf("str2[%d] eh (null)\n", i);
        }
    }
    puts("");
}

int EhPalindromo(char *str){
    int inicio = 0;
    int fim = strlen(str) - 1;

    while (inicio < fim){
        if (str[inicio++] != str[fim--]){
            return 0;
        }
    }
    return 1;
}

int main(void){
    char risada[51], copia[51] = {0};

    scanf("%s", risada);

    CopiaVogais(risada, copia);

    printf("risada = [%s]\n", risada);
    for (int i = 0; copia[i] != '\0'; i++){
        printf("copia[%d] = %c", i, copia[i]);
    }

    if (EhPalindromo(copia)){
        puts("S");
    }else{
        puts("N");
    }

    return 0;
}
