#include <stdio.h>

int Completude(const char *str){
    int i, j, letra[26] = {0}, soma = 0;

    //for percorre a string
    for (i = 0; str[i] != '\0'; i++){
        //for percorre o alfabeto
        for (j = 0; j < 26; j++){
            /*se o caractere atual for
            *igual a alguma letra minúscula
            *o array de contadores vai incrementar*/
            if (str[i] == ('a' + j)){
                letra[j]++;
            }
        }
    }
    //conta quantas letras apareceram
    for (i = 0; i < 26; i++){
        if (letra[i]){
            soma++;
        }
    }
    if (soma == 26){
        return 0;//frase completa
    }else if (13 < soma && soma < 26){
        return 1;//frase quase completa
    }else if (soma < 13){
        return 2;//frase mal elaborada
    }
}

int main(void){
    int N, i;
    char frase[1001];

    scanf("%d", &N);
    for (i = 0; i < N; i++){
        scanf("%*c");
        fgets(frase, 1001, stdin);
        switch (Completude(frase)){
            case 0:
                puts("frase completa");
                break;
            case 1:
                puts("frase quase completa");
                break;
            case 2:
                puts("frase mal elaborada");
                break;
        }
    }

    return 0;
}
