#include <stdio.h>

int main(void){
    int a, b, c, d, e;
    int b1, b2, b3, b4, b5;
    int par, imp, pos, neg;

    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);

    b1 = !(a % 2);
    b2 = !(b % 2);
    b3 = !(c % 2);
    b4 = !(d % 2);
    b5 = !(e % 2);

    par = b1 + b2 + b3 + b4 + b5;
    imp = 5 - par;

    b1 = (a > 0);
    b2 = (b > 0);
    b3 = (c > 0);
    b4 = (d > 0);
    b5 = (e > 0);
    pos = b1 + b2 + b3 + b4 + b5;

    b1 = (a < 0);
    b2 = (b < 0);
    b3 = (c < 0);
    b4 = (d < 0);
    b5 = (e < 0);
    neg = b1 + b2 + b3 + b4 + b5;

    printf("%d valor(es) par(es)\n", par);
    printf("%d valor(es) impar(es)\n", imp);
    printf("%d valor(es) positivo(s)\n", pos);
    printf("%d valor(es) negativo(s)\n", neg);

    return 0;
}
