#include <stdio.h>

int main(void){
    long long int N, i, somaCarneiros = 0, somaRoubado = 0;

    scanf("%lld", &N);
    long long int carneiros[N], roubado[N]; //roubado é uma array de flags pra cada sítio

    for (i = 0; i < N; i++){
        scanf("%lld", &carneiros[i]);
        roubado[i] = 0;
    }
    i = 0;
    while (1){
        if ((i == N) || (i < 0)){
            break;
        }
        if (carneiros[i] == 0){
            i--;
            continue;
        }
        roubado[i] = 1;
        if (carneiros[i] % 2 == 0){
            carneiros[i]--;
            i--;
        }else{
            carneiros[i]--;
            i++;
        }
    }
    for (i = 0; i < N; i++){
        somaCarneiros += carneiros[i];
        somaRoubado += roubado[i];
    }
    printf("%lld %lld\n", somaRoubado, somaCarneiros);

    return 0;
}
