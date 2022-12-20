#include <stdio.h>

int main(void){
    int n, Ri, i, cont;

    scanf("%d", &n);
    while (n){
        for (i = 0, cont = 0; i < n; i++){
            scanf("%d", &Ri);
            if (Ri){
                cont++;
            }
        }
        printf("Mary won %d times and John won %d times\n", n-cont, cont);
        scanf("%d", &n);
    }

    return 0;
}
