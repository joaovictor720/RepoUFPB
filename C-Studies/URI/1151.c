#include <stdio.h>

int main(void){
    int i = 0, j = 1, k;
    int n, cont = 1;

    scanf("%d", &n);

    while (cont <= n){
        k = j;
        j = i;
        printf("%d%c", i, (cont != n ? ' ' : '\n') );
        cont++;
        i = j + k;
    }

    return 0;
}
