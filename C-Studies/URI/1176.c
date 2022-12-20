#include <stdio.h>

unsigned long long Fib(int n){
    unsigned long long i = 0, j = 1, k;
    int cont = 0;

    while (cont < n){
        k = j;
        j = i;
        cont++;
        i = j + k;
    }
    return i;
}

int main(void){
    int i, t, n;
    unsigned long long fib;

    scanf("%d", &t);

    for(i = 0; i < t; i++){
        scanf("%d", &n);

        fib = Fib(n);
        printf("Fib(%d) = %llu\n", n, fib);
    }

    return 0;
}
