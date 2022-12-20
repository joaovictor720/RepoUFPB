#include <stdio.h>
#include <math.h>

int main(void){
    int C, i, j, xB, yB, x, y;
    int menor, dist, N, numBola;

    scanf("%d", &C);
    for (i = 0; i < C; i++){
        scanf("%d", &N);
        scanf("%d %d", &xB, &yB);

        menor = 10000;
        for (j = 0; j < N; j++){
            scanf("%d %d", &x, &y);

            dist = sqrt( pow(abs(xB) - abs(x), 2) + pow(abs(yB) - abs(y), 2) );
            if (dist < menor){
                menor = dist;
                numBola = j+1;
            }
        }
        printf("%d\n", numBola);
    }

    return 0;
}
