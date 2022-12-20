#include <stdio.h>

int main(void){
    int t, resp, cont, i;

    scanf("%d", &t);

    for (i = 0, cont = 0; i < 5; i++){
        scanf("%d", &resp);
        if (resp == t){
            cont++;
        }
    }
    printf("%d\n", cont);

    return 0;
}
