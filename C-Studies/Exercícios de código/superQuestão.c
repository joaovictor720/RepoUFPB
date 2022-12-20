#include <stdio.h>

    /****************
    *   quest�o 6   *
    ****************/
int EhArrayOrdenado(int ar[], int size){
    int i;

    for (i = 1; i < size; i++){
        if (ar[i] < ar[i-1] || ar[i] < ar[0]){
            return 0;
        }
    }
    return 1;
}
    /****************
    *   quest�o 6   *
    ****************/


    /****************
    *   quest�o 5   *
    ****************/
int MaximoValorArray(int ar[], int size){
    int maior = ar[0], i;

    for (i = 1; i < size; i++){
        if (ar[i] > maior){
            maior = ar[i];
        }
    }
    return maior;
}
    /****************
    *   quest�o 5   *
    ****************/


    /****************
    *   quest�o 4   *
    ****************/
int EmArray(int ar[], int size, int x){
    int i;

    for (i = 0; i < size; i++){
        if (x == ar[i]){
            return 1;
        }
    }
    return 0;
}
    /****************
    *   quest�o 4   *
    ****************/


    /****************
    *   quest�o 3   *
    ****************/
float MediaArray(int ar[], int size){
    int i, soma = 0;

    for (i = 0; i < size; i++){
        soma += ar[i];
    }
    return soma / size;
}
    /****************
    *   quest�o 3   *
    ****************/

int main(void){
    int ar[10]; //= {10, 20, 30, 40, 50, 60, 70, 80, 90, 100}; atribui��o inicial usada na quest�o 1
    int i, soma = 0;
    int sizeAr, x;

    /****************
    *   quest�o 2   *
    ****************/
    for (i = 0; i < 10; i++){
        printf("Digite o elemento %d do array: \n", i+1);
        scanf("%d", &ar[i]);
    }
    /****************
    *   quest�o 2   *
    ****************/


    /****************
    *   quest�o 1   *
    ****************/
    for (i = 0; i < 10; i++){
        printf("%2d elemento = %d\n", i+1, ar[i]);
    }

    for (i = 9; i >= 0; i--){
        printf("%2d elemento = %d\n", i+1, ar[i]);
    }

    printf("ar[4](quinto elemento) = %d\n", ar[4]);

    for (i = 0; i < 10; i++){
        if (i % 2){
            printf("ar[%d] = %d\n", i, ar[i]);
        }
    }

    for (i = 0; i < 10; i++){
        soma += ar[i];
    }
    printf("\nSoma do array: %d\n", soma);
    /****************
    *   quest�o 1   *
    ****************/


    /****************
    *   quest�o 3   *
    ****************/
    sizeAr = sizeof(ar) / sizeof(ar[0]);
    printf("\nMedia do array: %.2f\n", MediaArray(ar, sizeAr));
    /****************
    *   quest�o 3   *
    ****************/


    /****************
    *   quest�o 4   *
    ****************/
    printf("\nQual numero voce acha que esta no array: ");
    scanf("%d", &x);
    if (EmArray(ar, sizeAr, x)){
        printf("%d ESTAH no array.\n", x);
    }else{
        printf("%d NAO ESTAH no array.\n", x);
    }
    /****************
    *   quest�o 4   *
    ****************/


    /****************
    *   quest�o 5   *
    ****************/
    printf("\nMaior valor do array: %d\n", MaximoValorArray(ar, sizeAr));
    /****************
    *   quest�o 5   *
    ****************/


    /****************
    *   quest�o 6   *
    ****************/
    if (EhArrayOrdenado(ar, sizeAr)){
        puts("\nArray ordenado.");
    }else{
        puts("\nArray desordenado.");
    }
    /****************
    *   quest�o 6   *
    ****************/

    return 0;
}
