#include <stdio.h>

    /****************
    *   questão 6   *
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
    *   questão 6   *
    ****************/


    /****************
    *   questão 5   *
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
    *   questão 5   *
    ****************/


    /****************
    *   questão 4   *
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
    *   questão 4   *
    ****************/


    /****************
    *   questão 3   *
    ****************/
float MediaArray(int ar[], int size){
    int i, soma = 0;

    for (i = 0; i < size; i++){
        soma += ar[i];
    }
    return soma / size;
}
    /****************
    *   questão 3   *
    ****************/

int main(void){
    int ar[10]; //= {10, 20, 30, 40, 50, 60, 70, 80, 90, 100}; atribuição inicial usada na questão 1
    int i, soma = 0;
    int sizeAr, x;

    /****************
    *   questão 2   *
    ****************/
    for (i = 0; i < 10; i++){
        printf("Digite o elemento %d do array: \n", i+1);
        scanf("%d", &ar[i]);
    }
    /****************
    *   questão 2   *
    ****************/


    /****************
    *   questão 1   *
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
    *   questão 1   *
    ****************/


    /****************
    *   questão 3   *
    ****************/
    sizeAr = sizeof(ar) / sizeof(ar[0]);
    printf("\nMedia do array: %.2f\n", MediaArray(ar, sizeAr));
    /****************
    *   questão 3   *
    ****************/


    /****************
    *   questão 4   *
    ****************/
    printf("\nQual numero voce acha que esta no array: ");
    scanf("%d", &x);
    if (EmArray(ar, sizeAr, x)){
        printf("%d ESTAH no array.\n", x);
    }else{
        printf("%d NAO ESTAH no array.\n", x);
    }
    /****************
    *   questão 4   *
    ****************/


    /****************
    *   questão 5   *
    ****************/
    printf("\nMaior valor do array: %d\n", MaximoValorArray(ar, sizeAr));
    /****************
    *   questão 5   *
    ****************/


    /****************
    *   questão 6   *
    ****************/
    if (EhArrayOrdenado(ar, sizeAr)){
        puts("\nArray ordenado.");
    }else{
        puts("\nArray desordenado.");
    }
    /****************
    *   questão 6   *
    ****************/

    return 0;
}
