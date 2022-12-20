#include <stdio.h>

int main(void){
    int i = 1, r1, r2, n;

    scanf("%d", &n);
    while (i <= n){
        scanf("%d %d", &r1, &r2);
        printf("%d\n", r1+r2);
        i = i + 1;
    }

    return 0;
}
