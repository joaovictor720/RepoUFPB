#include <stdio.h>

void OrdenaContaArray(int ar[], int size, int *contador){
    int trocou, i, aux, cont[1001] = {0};

    while (1){
        trocou = 0;
        for (i = 0; i < size - 1; i++){
            if (ar[i] < ar[i+1]){
                aux = ar[i];
                ar[i] = ar[i+1];
                ar[i+1] = aux;
                trocou = 1;
                cont[i]++;
                cont[i+1]++;
            }
        }
        if (!trocou){
            break;
        }
    }
    for (i = 0; i < size; i++){
        if (cont[i] == 0){
            *contador = *contador + 1;
        }
    }
}

int main(void){
    int i, j, test, M, nota[1001], contador;

    scanf("%d", &test);
    for (i = 0; i < test; i++){
        scanf("%d", &M);

        for (j = 0; j < M; j++){
            scanf("%d", &nota[j]);
        }
        contador = 0;
        OrdenaContaArray(nota, M, &contador);
        printf("%d\n", contador);
    }

    return 0;
}
