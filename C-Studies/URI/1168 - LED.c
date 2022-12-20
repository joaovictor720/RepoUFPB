#include <stdio.h>
#include <string.h>
#include <math.h>

int Leds(const char *str){
    int soma = 0, i;
    char leds[2][11] = { "1234567890",
                         "2554563766" };

    for (i = 0; str[i] != '\0'; i++){
        soma += (int) (*(strchr(leds[0], str[i]) + 11)) - 48;
    }

    return soma;
}

int main(void){
    int N, i;
    char V[100];

    scanf("%d", &N);
    for (i = 0; i < N; i++){
        scanf("%s", V);
        printf("%d leds\n", Leds(V));
    }

    return 0;
}
