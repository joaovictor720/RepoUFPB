#include <stdio.h>
#include <math.h>

int main(void){
    unsigned i, j, n, teste, primo;

    scanf("%u", &teste);

    for (j = 0; j < teste; j++){
        scanf("%u", &n);

        if (n == 1){
            printf("Not Prime\n");
        }else{
            primo = 1;
            for (i = 2; i <= sqrt(n); i++){
                if (n % i == 0){
                    printf("Not Prime\n");
                    primo = 0;
                    break;
                }
                primo = 1;
            }
            if (primo){
                printf("Prime\n");
            }
        }
    }

    return 0;
}
