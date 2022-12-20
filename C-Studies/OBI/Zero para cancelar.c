#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    int t, i, ar[100000] = {0}, x, soma = 0, contZero = 0, paDois[100000];

    paDois[0] = 1;
    for (i = 1; i < 100000; i++){
        paDois[i] = paDois[i-1]+2;
    }

    for (i = 0; i < 5; i++){
        printf("paDois[%d] = %d\n", i, paDois[i]);
    }

    scanf("%d", &t);
    for (i = 0; i < t; i++){
        scanf("%d", &x);
        if (x == 0){
            contZero++;
            ar[ i - paDois[contZero-1] ] = 0;
        }else{
            contZero = 0;
            ar[i] = x;
        }
    }
    for (i = 0; i < t; i++){
        soma += ar[i];
    }
    printf("%d\n", soma);

    return 0;
}
