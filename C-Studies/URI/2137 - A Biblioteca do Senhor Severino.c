#include <stdio.h>
#include <string.h>

void OrdenaStrings(char ar[][6], int nStr){
    int i, trocou;
    char aux[5];

    while (1){
        trocou = 0;
        for (i = 0; i < nStr - 1; i++){
            if (strcmp( ar[i], ar[i+1] ) > 0){
                strcpy(aux, ar[i]);
                strcpy(ar[i], ar[i+1]);
                strcpy(ar[i+1], aux);
                trocou = 1;
            }
        }
        if (!trocou){
            break;
        }
    }
}

void RemoveNL(char *str){
    str[strlen(str) - 1] = '\0';
}

int main(void){
    int t, i, j;
    char codigos[1000][6];

    while (scanf("%d", &t) != EOF){
        scanf("%*c");
        for (i = 0; i < t; i++){
            fgets(codigos[i], 6, stdin);
            RemoveNL(codigos[i]);
        }
        OrdenaStrings(codigos, t);
        for (i = 0; i < t; i++){
            printf("%s\n", codigos[i]);
        }
    }

    return 0;
}
