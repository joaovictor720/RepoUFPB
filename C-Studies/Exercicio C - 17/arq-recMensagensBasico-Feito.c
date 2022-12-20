#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int codMensagem;
    int indice;
    char letra;
}tLetra;

int main(void){
    FILE *fp;
    tLetra letra;
    char mensagem[10][201] = {0};
    int i;

    fp = fopen("mensagens.dat", "rb");
    if (fp == NULL) { //verificar se conseguiu abrir
        return 1;
    }

    while(1){
        //ler uma letra com fread
        //fread(endereco da variavel, tamanho do tipo da variavel, 1 unidade, fp);
        fread(&letra, sizeof(letra), 1, fp);
        if (feof(fp) || ferror(fp)){
            break;
        }
        //fazer algo com a letra
        mensagem[letra.codMensagem][letra.indice] = letra.letra;

        //for pra tirar uns caracteres estranhos que tavam final das mensagens \0/
        for (i = 0; mensagem[letra.codMensagem][i] != 0; i++){
            if (mensagem[letra.codMensagem][i] == 0){
                mensagem[letra.codMensagem][i] = '\0';
            }
        }
    }
    fclose(fp); //nao esquecer

    //imprimir mensagens
    for (i = 0; i < 10; i++){
        printf("Mensagem #%d: %s\n", i+1, mensagem[i]);
    }

    return 0;
}
