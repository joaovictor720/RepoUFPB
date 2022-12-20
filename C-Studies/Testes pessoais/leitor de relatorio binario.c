#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    FILE *fp;
    char str[65];

    fp = fopen("relatorioTeste.dat", "rb");

    fread(str, sizeof(str[0]), 65, fp);
    printf("%s", str);

    fclose(fp);

    return 0;
}
