#include <stdio.h>
#include <string.h>

int main(void){
    char D[101], S[101];

    while (scanf("%s", D) != EOF){
        scanf("%s", S);
        if (strstr(D, S) == NULL){
            puts("Nao resistente");
        }else{
            puts("Resistente");
        }
    }

    return 0;
}
