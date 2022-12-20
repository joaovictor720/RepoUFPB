#include <stdio.h>

int main(void){
    int a, b, c;
    int i, j, k;

    scanf("%d%d%d", &a, &b, &c);
    i = a;
    j = b;
    k = c;

    if (a > c) {
        int x = c;
        c = a;
        a = x;
    }
    if (a > b) {
        int x = b;
        b = a;
        a = x;
    }
    if (b > c) {
        int x = c;
        c = b;
        b = x;
    }

    printf("%d\n%d\n%d\n\n", a, b, c);
    printf("%d\n%d\n%d\n", i, j, k);

    return 0;
}
