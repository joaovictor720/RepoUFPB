#include <stdio.h>

int main(void){
    int v, s, t;
    float L;

    scanf("%d%d", &t, &v);

    s = t * v;
    L = s / 12.0;

    printf("%.3f\n", L);

    return 0;
}
