#include <stdio.h>

int main(void){
    float n1, n2, n3, n4, n5, n6;
    int v1, v2, v3, v4, v5, v6;
    int s;

    scanf("%f%f%f", &n1, &n2, &n3);
    scanf("%f%f%f", &n4, &n5, &n6);

    v1 = (n1 > 0);
    v2 = (n2 > 0);
    v3 = (n3 > 0);
    v4 = (n4 > 0);
    v5 = (n5 > 0);
    v6 = (n6 > 0);

    s = v1 + v2 + v3 + v4 + v5 + v6;
    printf("%d valores positivos\n", s);

    return 0;
}
