#include <stdio.h>

int main(void){
    int t, n, max, peso, pTotal, viag, i, j;

    scanf("%d", &t);

    for (i = 0; i < t; i++){
        scanf("%d%d", &n, &max);

        for (j = 0, pTotal = 0, viag = 1; j < n; j++){
            scanf("%d", &peso);

            pTotal += peso;
            if (pTotal > max){
                pTotal = peso;
                viag++;
                continue;
            }
        }
        printf("%d\n", viag);
    }

    return 0;
}
