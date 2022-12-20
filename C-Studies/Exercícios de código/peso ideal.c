#include <stdio.h>

int main(void){
    char s;
    float h, iw;/*iw significa ideal weight, coloquei assim só pra não ficar p nem pi*/

    puts("Defina seu sexo como M(masculino) ou F(feminino): ");
    scanf("%c", &s);
    puts("Informe sua altura: ");
    scanf("%f", &h);

    if (s == 'M' || 'm'){
        iw = (72.7*h) - 58;
        printf("\nSeu peso ideal seria %.1f\n", iw);
    }else{
        if (s == 'F' || 'f'){
            iw = (62.1*h) - 44.7;
            printf("\nSeu peso ideal seria %.1f\n", iw);
        }
    }

    return 0;
}
