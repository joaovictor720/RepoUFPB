#include <stdio.h>

int main(void){
    int N, i, j;
    float C;

    scanf("%d", &N);

    for (i=1; i <= N; i++){
        scanf("%f", &C);

        for (j=0; C > 1; j++){
            C /= 2;
        }
        printf("%d dias\n", j);
    }

    return 0;
}
