#include <stdio.h>

int main(void){
    int i, t, pa, pb, anos;
    double g1, g2;

    scanf("%d", &t);

    for (i = 0; i < t; i++){
        anos = 0;
        scanf("%d%d", &pa, &pb);
        scanf("%lf%lf", &g1, &g2);

        while (pa <= pb){
            pa = pa * ((g1/100) + 1);
            pb = pb * ((g2/100) + 1);
            anos++;
            if (anos > 100){
                puts("Mais de 1 seculo.");
                break;
            }
        }
        if (anos <= 100){
            printf("%d anos.\n", anos);
        }

    }

    return 0;
}
