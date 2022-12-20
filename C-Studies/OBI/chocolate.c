#include <stdio.h>
#include <string.h>

int main(void){
    int i, j, n, x1, y1, x2, y2;
    int flag1 = 0, flag2 = 0;
    int chocolate[500][500] = {0};

    if (scanf("%d", &n) == 1);

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            chocolate[i][j] = 0;
        }
    }
    if (scanf("%d %d", &x1, &y1) == 1);
    if (scanf("%d %d", &x2, &y2) == 1);

    chocolate[x1-1][y1-1] = 1;
    chocolate[x2-1][y2-1] = 1;

    for (i = 0; i < n; i++){
        for (j = 0; j < n/2; j++){
            if (chocolate[i][j]){
                flag1 = 1;
            }
        }
    }
    for (i = 0; i < n; i++){
        for (j = 0; (j+(n/2)) < n; j++){
            if (chocolate[i][j]){
                flag2 = 1;
            }
        }
    }
    for (i = 0; i < n/2; i++){
        for (j = 0; j < n; j++){
            if (chocolate[i][j]){
                flag1 = 1;
            }
        }
    }
    for (i = 0; (i+(n/2)) < n; i++){
        for (j = 0; j < n; j++){
            if (chocolate[i][j]){
                flag2 = 1;
            }
        }
    }

    if (flag1 && flag2){
        puts("S");
    }else{
        puts("N");
    }

    return 0;
}
