#include <stdio.h>

void Parear();

int main(void){
    int idade[1000], virus, i;

    while (scanf("%d", &virus) != EOF){
        for (i = 0; i < virus; i++){
            scanf("%d", &idade[i]);
        }
        for (i = 0; i < (virus/2) - 1; i++){
            Parear();
        }
    }

    return 0;
}
