#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    FILE *fp;
    char coringa, arq[51];
    int cont;

    printf("Inserir nome do arquivo de texto: ");
    scanf("%s", arq);

    fp = fopen(arq, "r");

    while (1){
        fread(&coringa, sizeof(coringa), 1, fp);
        if (feof(fp)){
            break;
        }
        if (coringa == '\n'){
            cont++;
        }
    }

    printf("\n%d contatos.", cont);

    return 0;
}
