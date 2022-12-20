#include <stdio.h>

int Suicidio(int array[], int size, int salto){
    int i, indice, mortos = 0;

    while (1){
        for (i = 0; i < size; i++){
            if (array[i] == 0){
                mortos++;
            }
        }
        if (mortos == size-1){
            for (i = 0; i < size; i++){
                if (array[i] > 0){
                    return array[i];
                }
            }
        }
        for (i = 0; i < size; i++){
            indice = i + salto + 1;
            if (indice < size){
                if (array[indice] > 0){
                    array[indice] = 0;
                }
            }else{
                indice = indice - size;
                if (array[indice] > 0){
                    array[indice] = 0;
                }
            }
        }
    }
}

void NumeraArray(int array[], int size){
    for (int i = 0; i < size; i++){
        array[i] = i+1;
    }
}

int main(void){
    int n, salto, i, T, vivo;

    scanf("%d", &T);

    for(i = 0; i < T; i++){
        scanf("%d", &n);
        scanf("%d", &salto);
        int circulo[n];

        NumeraArray(circulo, n);
        vivo = Suicidio(circulo, n, salto);
        printf("Case %d: \n", i, vivo);
    }

    return 0;
}
