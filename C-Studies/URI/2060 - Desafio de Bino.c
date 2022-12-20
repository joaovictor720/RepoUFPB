#include <stdio.h>

void Multiplos(int L[], int sizeL, int cont[]){
    int i;

    for (i = 0; i < sizeL; i++){
        if (L[i] % 2 == 0){
            cont[0]++;
        }
        if (L[i] % 3 == 0){
            cont[1]++;
        }
        if (L[i] % 4 == 0){
            cont[2]++;
        }
        if (L[i] % 5 == 0){
            cont[3]++;
        }
    }
}

int main(void){
    int n, i, cont[4] = {0};

    scanf("%d", &n);
    int L[n];

    for (i = 0; i < n; i++){
        scanf("%d", &L[i]);
    }

    Multiplos(L, n, cont);
    printf("%d Multiplo(s) de 2\n", cont[0]);
    printf("%d Multiplo(s) de 3\n", cont[1]);
    printf("%d Multiplo(s) de 4\n", cont[2]);
    printf("%d Multiplo(s) de 5\n", cont[3]);

    return 0;
}
