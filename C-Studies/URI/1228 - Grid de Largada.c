#include <stdio.h>

void ComparaUltrapassagem(int ar1[], int ar2[], int size, int *contador){
    int i, j, aux, flagCont = 0;

    while (1){
        if (flagCont >= size){
            break;
        }

        for (i = 0; i < size; i++){
            for (j = 0; j < size; j++){
                if (ar2[i] == ar1[j] && i > j){
                    *contador = *contador + (i - j);
                    aux = ar1[i];
                    ar1[i] = ar1[j];
                    ar1[j] = aux;
                }
            }
        }
        //aqui vão ser contados quais pares de mesmo índice são iguais
        //se ar1 == ar2 para todos os índices, o contador terá o tamanho do array
        flagCont = 1;
        for (j = 0; j < size; j++){
            if (ar1[i] == ar2[j]){
                flagCont++;
            }
        }
    }
}

int main(void){
    int N, i, cont;

    while (1){
        scanf("%d", &N);
        int largada[N], chegada[N];

        for (i = 0; i < N; i++){
            scanf("%d", &largada[i]);
        }
        for (i = 0; i < N; i++){
            scanf("%d", &chegada[i]);
        }
        cont = 0;
        ComparaUltrapassagem(largada, chegada, N, &cont);
        printf("%d\n", cont);
    }

    return 0;
}
