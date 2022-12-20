#include <stdio.h>

int main(void){
    int i, j, I, J;

    scanf("%d %d", &I, &J);
    int matriz[I][J];

    for (i = 0; i < I; i++){
        for (j = 0; j < J; j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    for (i = 0; i < I; i++){
        for (j = 0; j < J; j++){
            if (matriz[i][j] == 42){

                if (matriz[i-1][j-1] == 7 && matriz[i-1][j] == 7 && matriz[i-1][j+1] == 7){

                    if (matriz[i][j-1] == 7 && matriz[i][j+1] == 7){

                        if (matriz[i+1][j-1] == 7 && matriz[i+1][j] == 7 && matriz[i+1][j+1] == 7){
                            printf("%d %d\n", i+1, j+1);
                            return 0;
                        }
                    }
                }
            }
        }
    }

    puts("0 0");

    return 0;
}
