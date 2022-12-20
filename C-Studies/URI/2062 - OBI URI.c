#include <stdio.h>
#include <string.h>

char *Corrige(char *str){
    if (strlen(str) == 3){
        if (strstr(str, "UR") != NULL){
            return "URI";
        }
        if (strstr(str, "OB") != NULL){
            return "OBI";
        }
    }
    return str;
}

int main(void){
    int T, i;
    char obiuri[21];

    scanf("%d", &T);
    for (i = 0; i < T; i++){
        scanf("%s", obiuri);
        printf("%s%s", Corrige(obiuri), i == T-1? "" : " ");
    }
    printf("\n");

    return 0;
}
