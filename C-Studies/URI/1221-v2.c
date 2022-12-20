#include <stdio.h>
#include <math.h>

int IsPrime(int n){
    int i;

    if (n == 1){
        return 0;
    }else{
        for (i = 2; i <= sqrt(n); i++){
            if (n % i == 0){
                return 0;
            }
        }
        if (1){
            return 1;
        }
    }
}

int main(void){
    int i, n, teste;

    scanf("%u", &teste);

    for (i = 0; i < teste; i++){
        scanf("%u", &n);

        if (IsPrime(n)){
            puts("Prime");
        }else{
            puts("Not Prime");
        }
    }
    return 0;
}
