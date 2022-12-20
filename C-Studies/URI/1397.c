#include <stdio.h>

int main(void){
    int n, a, b, i, contA, contB;

    scanf("%d", &n);
    while (n){
        contA = contB = 0;
        for (i = 0; i < n; i++){
            scanf("%d %d", &a, &b);

            if (a > b){
                contA++;
            }else if (a < b){
                contB++;
            }
        }
        printf("%d %d\n", contA, contB);
        scanf("%d", &n);
    }

    return 0;
}
