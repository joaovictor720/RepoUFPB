#include <stdio.h>

int main(void){
    int a, b, c;

    puts("Digite 3 valores: ");
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    if (a > b){
        if (a > c){
            printf("O maior eh %d", a);
        }else{
            printf("O maior eh %d", c);
        }
    }else{
        if (b > c){
            printf("O maior eh %d", b);
        }else{
            printf("O maior eh %d", c);
        }

    }

    return 0;
}
