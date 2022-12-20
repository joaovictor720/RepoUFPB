#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    char baralho[53], *p, cartaTemp[4];
    int i, j, contNum[14] = {0}, contC = 0, contE = 0, contU = 0, contP = 0, flagC = 0, flagE = 0, flagU = 0, flagP = 0, index;

    scanf("%s", baralho);

    for (i = 0; i < 52; i+=3){
        index = strtod(&baralho[i], &p)-1;
        contNum[index]++;

        if (*p == 'C'){
            contC++;
        }else if (*p == 'E'){
            contE++;
        }else if (*p == 'U'){
            contU++;
        }else if (*p == 'P'){
            contP++;
        }
        for (j = 0; j < 4; j++){
            if (j == 3){
                cartaTemp[j] = '\0';
                break;
            }
            cartaTemp[j] = baralho[i+j];
        }
        if (i+3 != (strlen(baralho)-1)){
            if (strstr(&baralho[i+3], cartaTemp) != NULL){
                if (*p == 'C'){
                    flagC = 1;
                }else if (*p == 'E'){
                    flagE = 1;
                }else if (*p == 'U'){
                    flagU = 1;
                }else if (*p == 'P'){
                    flagP = 1;
                }
            }
        }
    }

    if (flagC){
        puts("erro");
    }else{
        printf("%d\n", 13-contC);
    }
    if (flagE){
        puts("erro");
    }else{
        printf("%d\n", 13-contE);
    }
    if (flagU){
        puts("erro");
    }else{
        printf("%d\n", 13-contU);
    }
    if (flagP){
        puts("erro");
    }else{
        printf("%d\n", 13-contP);
    }


    return 0;
}
