#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void RemoveNL(char *str){
    str[strlen(str)-1] = '\0';
}

int main(void){
    char pomekons[1001][1001];
    int i, n, cont = 0;

    scanf("%d%*c", &n);
    for (i = 0; i < n; i++){
        fgets(pomekons[i], 101, stdin);
        RemoveNL(pomekons[i]);
    }

    for (i = 0; i < n-1; i++){
        if (strcmp(pomekons[i], pomekons[i+1])){
            cont++;
        }
    }

    printf("Falta(m) %d pomekon(s).\n", 151-1-cont);

    return 0;
}
