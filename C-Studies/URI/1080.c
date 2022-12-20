#include <stdio.h>

int main(void){
    int x, i, maior = 0, pos;

    for (i=1; i <= 100; i++){
        scanf("%d", &x);

        if (x > maior){
            maior = x;
            pos = i;
        }
    }
    printf("%d\n", maior);
    printf("%d\n", pos);

    return 0;
}
