#include <stdio.h>

int main(void){
    int idade;

    printf("Insira sua idade: ");
    scanf("%d", &idade);

    if (idade <= 21){
        printf("Voce eh um(a) jovem");
    }else if (idade <= 60){
        printf("Voce eh um(a) adulto(a)");
    }else{
        printf("Voce eh um(a) idoso(a)");
    }

    return 0;
}
