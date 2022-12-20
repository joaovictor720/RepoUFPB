#include <stdio.h>

int main(void){
    int i, j = 1, k;
    int n;

    puts("Insert a size for the Fibonacci sequence:");
    puts("(It is the biggest number you want, at least, to be shown)");
    scanf("%d", &n);

    for (i = 0; i <= n; i = j + k){
        printf("%d\n", i);
        k = j;
        j = i;
    }

    return 0;
}
