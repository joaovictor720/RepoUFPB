#include <stdio.h>
#include <math.h>

int main(void){
    int a, b, c;
    int m;

    scanf("%d%d%d", &a, &b, &c);

    m = (a + b + abs(a - b) ) / 2;
    m = (m + c + abs(m - c) ) / 2;
    printf("%d eh o maior\n", m);

    return 0;
}
