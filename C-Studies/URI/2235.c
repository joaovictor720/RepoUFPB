#include <stdio.h>

int main(void){
    int a, b, c;

    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    if (a == b || a == c || b == c || a + b == c || a == b + c || a + c == b){
        printf("S\n");
    }else{
        printf("N\n");
    }

    return 0;
}
