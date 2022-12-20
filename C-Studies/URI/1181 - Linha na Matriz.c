#include <stdio.h>

int main(void){
    int L, i, j;
    double M[12][12], soma = 0;
    char OP;

    scanf("%d%*c", &L);
    scanf("%c", &OP);

    for (i = 0; i < 12; i++){
        for (j = 0; j < 12; j++){
            scanf("%lf", &M[i][j]);
        }
    }
    for (j = 0; j < 12; j++){
        soma += M[L][j];
    }
    if (OP == 'S'){
        printf("%.1lf\n", soma);
    }else{
        printf("%.1lf\n", soma/12);
    }

    return 0;
}
