#include <stdio.h>

int main(void){
    int freq, N, i, perg, cont[1000], soma; //perg para as perguntas
        //freq � o crit�rio para uma pergunta ser frequente

    while (1){
        scanf("%d %d", &N, &freq);

        if (!(N || freq)){
            return 0; //condi��o de parada: N = freq = 0
        }

        for (i = 0; i < N; i++){
            cont[i] = 0;
        }

        for (i = 0; i < N; i++){
            scanf("%d", &perg);
            cont[perg - 1]++;
        }

        soma = 0;
        for (i = 0; i < N; i++){
            if (cont[i] >= freq){
                soma++;
            }
        }
        printf("%d\n", soma);
    }

    return 0;
}
