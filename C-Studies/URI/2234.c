#include <stdio.h>

int main(void){
    int h, p;
    double m;

    scanf("%d %d", &h, &p);

    m = 1.0*h / p;
    printf("%.2lf\n", m);

    return 0;
}
