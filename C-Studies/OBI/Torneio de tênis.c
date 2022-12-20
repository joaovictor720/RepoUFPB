#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    int i, cont = 0;
    char resultado;

    for (i = 0; i < 6; i++){
        scanf("%c%*c", &resultado);
        if (resultado == 'V'){
            cont++;
        }
    }

    if (cont >= 5){
        puts("1");
    }else if (cont >= 3){
        puts("2");
    }else if (cont >= 1){
        puts("3");
    }else{
        puts("-1");
    }

    return 0;
}
