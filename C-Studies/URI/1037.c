#include <stdio.h>

int main(void){
    float v;

    scanf("%f", &v);

    if (0 <= v&&v <= 25){
        printf("Intervalo [0,25]\n");
    }else if (25 < v&&v <= 50){
        printf("Intervalo (25,50]\n");
    }else if (50 < v&&v <= 75){
        printf("Intervalo (50,75]\n");
    }else if (75 < v&&v <= 100){
        printf("Intervalo (75,100]\n");
    }else{
        printf("Fora de intervalo\n");
    }

    return 0;
}
