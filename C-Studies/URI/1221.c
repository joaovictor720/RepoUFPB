#include <stdio.h>

int main(void){
    unsigned i, j, n, teste, primo = 1;

    scanf("%u", &teste);

    for (j = 0; j < teste; j++){
        scanf("%u", &n);

        if (n == 1){
            printf("Not prime\n");
            continue;
        }
        primo = 1;
        for (i = 2; i < n; i++){
            if (n % i == 0){
                printf("Not prime\n");
                primo = 0;
                break;
            }
            primo = 1;
        }
        if (primo){
            printf("Prime\n");
        }
    }

    return 0;
}
