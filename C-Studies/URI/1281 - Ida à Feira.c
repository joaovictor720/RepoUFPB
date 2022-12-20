#include <stdio.h>
#include <string.h>

#define LIMIT 50

int main(void){
    int i, j, n, m, p;
    float precos[LIMIT], qtd[LIMIT], somaPreco;
    char disp[LIMIT][LIMIT], comprar[LIMIT][LIMIT];

    scanf("%d%*c", &n);
    while (n--){
        somaPreco = 0;

        scanf("%d", &m);
        for (i = 0; i < m; i++){
            scanf("%s", disp[i]);
            scanf("%f%*c", &precos[i]);
        }
        scanf("%d", &p);
        for (i = 0; i < p; i++){
            scanf("%s", comprar[i]);
            scanf("%f%*c", &qtd[i]);
        }

        for (i = 0; i < m; i++){
            for (j = 0; j < p; j++){
                if (!strcmp(disp[i], comprar[j])){
                    somaPreco += precos[i]*qtd[j];
                }
            }
        }

        printf("R$ %.2f\n", somaPreco);
    }

    return 0;
}
