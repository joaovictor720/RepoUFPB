#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void TiraNL(char *str){
    str[strlen(str)-1] = '\0';
}

int main(void){
    FILE *fp;
    char nome_disciplina[51], str[65] = "Disciplina: ";

    fgets(nome_disciplina, 51, stdin);
    TiraNL(nome_disciplina);

    strcat(str, nome_disciplina);
    strcat(str, "\n");

    fp = fopen("relatorioTeste.dat", "wb");

    fwrite(str, sizeof(str[0]), strlen(str), fp);

    fclose(fp);
    return 0;
}
