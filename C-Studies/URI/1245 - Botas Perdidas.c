#include <stdio.h>

int main(void){
    int N, i, j, cont;

    while (scanf("%d", &N) != EOF){
        int tamanho[N];
        char lado[N];

        cont = 0;
        for (i = 0; i < N; i++){
            scanf("%d %c%*c", &tamanho[i], &lado[i]);
        }
        for (i = 0; i < N; i++){
            for (j = 1; j < N; j++){
                if (tamanho[i] == tamanho[j]){
                    if (lado[i] != lado[j]){
                        cont++;
                        tamanho[i] = tamanho[j] = lado[i] = lado[j] = 0;
                        break;
                    }
                }
            }
        }
        printf("%d\n", cont);
    }

    return 0;
}
