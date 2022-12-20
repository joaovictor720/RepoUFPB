#include <stdio.h>

int Rafael(int x, int y){
    return 9*x*x + y*y;
}

int Beto(int x, int y){
    return 2*x*x + 25*y*y;
}

int Carlos(int x, int y){
    return y*y*y - 100*x;
}

int main(void){
    int x, y, i, n, R, B, C;

    scanf("%d", &n);

    for (i = 0; i < n; i++){
        scanf("%d%d", &x, &y);

        R = Rafael(x, y);
        B = Beto(x, y);
        C = Carlos(x, y);
        if (R > B){
            if (R > C){
                puts("Rafael ganhou");
            }else{
                puts("Carlos ganhou");
            }
        }else{
            if (B > C){
                puts("Beto ganhou");
            }else{
                puts("Carlos ganhou");
            }
        }
    }

    return 0;
}
