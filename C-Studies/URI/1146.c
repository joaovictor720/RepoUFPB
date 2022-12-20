#include <stdio.h>

int main(void){
    int X, i;

    scanf("%d", &X);

    while (X){
        for (i = 1; i <= X; i++){
            if (i < X){
                printf("%d ", i);
            }
            if (i == X){
                printf("%d\n", i);
            }
        }
        scanf("%d", &X);
    }

    return 0;
}
