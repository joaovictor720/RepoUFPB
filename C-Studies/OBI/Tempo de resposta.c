#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    int i, n, amigosE[100] = {0}, amigosR[100] = {0}, tempoAmigo[100] = {0}, X, somaTempo = 0, naoTeveTempo = 0;
    char registro;

    scanf("%d%*c", &n);
    for (i = 0; i < n; i++){
        scanf("%c", &registro);
        if (registro == 'T'){
            scanf("%d%*c", &X);
            somaTempo += X;
            naoTeveTempo = 0;
        }else{
            naoTeveTempo++;
            scanf("%d%*c", &X);
            if (registro == 'E'){
                amigosE[X-1] = 1;
            }else if (registro == 'R'){
                amigosR[X-1] = 1;
            }
            if (!(amigosR[X-1] && amigosE[X-1])){
                tempoAmigo[X-1]++;
            }
        }
        if (naoTeveTempo){
            somaTempo++;
        }
    }
    for (i = 0; i < 100; i++){
        if (!amigosE){
            printf("%d -1\n", i+1);
        }else if (tempoAmigo[i]){
            printf("%d %d\n", i+1, somaTempo+tempoAmigo[i]);
        }
    }

    return 0;
}
