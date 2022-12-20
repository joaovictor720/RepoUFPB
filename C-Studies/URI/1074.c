#include <stdio.h>

int main(void){
    int X, N, i;

    scanf("%d", &N);

    for (i = 0; i < N; i=i+1){
        scanf("%d", &X);
        if (X == 0){
            printf("NULL\n");
        }
        if (X % 2 == 0 && (X != 0)){
            printf("EVEN ");
        }else if (X % 2 != 0 && (X != 0)){
            printf("ODD ");
        }
        if (X > 0){
            printf("POSITIVE\n");
        }else if (X < 0){
            printf("NEGATIVE\n");
        }
    }

    return 0;
}
