#include <stdio.h>

#define MAX 10000000

int main(void){
    int i, j, n, x;

    scanf("%d", &n);

    for (i = 1; i <= n; i++){
        scanf("%d", &x);

        for (j = 2; j < x; j++){
            if (x % j == 0){
                printf("%d nao eh primo\n", x);
                j += MAX;
            }
        }
        if (j < MAX){
            printf("%d eh primo\n", x);
        }
    }

    return 0;
}
