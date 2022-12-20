#include <stdio.h>

int main(void){
    char tipo;
    int n, quantia, i;
    int R = 0, S = 0, C = 0, total = 0;
    float percR, percS, percC;

    scanf("%d", &n);

    for (i = 0; i < n; i++){
        scanf("%d%*c %c", &quantia, &tipo);
        switch (tipo){
            case 'C':
                total += quantia;
                C += quantia;
                break;
            case 'R':
                total += quantia;
                R += quantia;
                break;
            case 'S':
                total += quantia;
                S += quantia;
                break;
        }
    }
    percC = (float) C * 100 / total;
    percR = (float) R * 100 / total;
    percS = (float) S * 100 / total;

    printf("Total: %d cobaias\n", total);
    printf("Total de coelhos: %d\n", C);
    printf("Total de ratos: %d\n", R);
    printf("Total de sapos: %d\n", S);
    printf("Percentual de coelhos: %.2f %%\n", percC);
    printf("Percentual de ratos: %.2f %%\n", percR);
    printf("Percentual de sapos: %.2f %%\n", percS);

    return 0;
}
