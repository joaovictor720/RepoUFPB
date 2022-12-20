#include <stdio.h>

int main(void){
    int origin, pessoas, T, cont, i;

    while (1){
        scanf("%d %d", &origin, &pessoas);
        if(!(origin || pessoas)){
            break;
        }
        if(!(origin && pessoas)){
            continue;
        }
        int repetidos[origin + 1];

        for(i = 0; i <= origin; i++){
            repetidos[i] = 0;
        }
        for(i = 0; i < pessoas; i++){
            scanf("%d", &T);
            repetidos[T]++;
        }
        cont = 0;
        for(i = 0; i <= origin; i++){
            if(repetidos[i] > 1){
                cont++;
            }
        }
        printf("%d\n", cont);
    }

    return 0;
}
