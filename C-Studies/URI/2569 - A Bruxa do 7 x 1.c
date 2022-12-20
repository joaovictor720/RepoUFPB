#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SeteParaZero(char *str){
    int i;
    for (i = 0; str[i] != '\0'; i++){
        if (str[i] == '7'){
            str[i] = '0';
        }
    }
}

char *TiraZeroEsquerda(char *str){
    int i;
    for (i = 0; str[i] != '\0'; i++){
        if (str[i] != '0'){
            return &str[i];
        }
    }
}

int main(void){
    char num1[6], num2[6], op, S[10], P[10];
    int soma, produto;

    scanf("%s", num1);
    scanf("%*c%c%*c", &op);
    scanf("%s", num2);

    SeteParaZero(num1);
    SeteParaZero(num2);

    if (op == '+'){
        soma = atoi(num1)+atoi(num2);
        sprintf(S, "%d", soma);
        SeteParaZero(S);

        printf("%s\n", TiraZeroEsquerda(S) == NULL ? "0" : TiraZeroEsquerda(S));
    }else if (op == 'x'){
        produto = atoi(num1)*atoi(num2);
        sprintf(P, "%d", produto);
        SeteParaZero(P);

        printf("%s\n", TiraZeroEsquerda(P) == NULL ? "0" : TiraZeroEsquerda(P));
    }

    return 0;
}
