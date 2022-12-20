#include <stdio.h>

int main(void){
    double a, b, c;
    double x;

    scanf("%lf %lf %lf", &a, &b, &c);

    //abaixo, o código vai permutar os valores em ordem crescente.
    if (a > b && a > c){
        a = a;
        b = b;
        c = c;
    }else if (b > c){
        x = a + b;
        a = x - a;
        b = x - b;
        c = c;
    }else{
        x = a + c;
        a = x - a;
        b = b;
        c = x - c;
    }
    if (a >= b + c){
        printf("NAO FORMA TRIANGULO\n");
        return 0;
    }
    //identifica quanto aos ângulos.
    if ( (a*a) == (b*b) + (c*c) ){
        printf("TRIANGULO RETANGULO\n");
    }else if ( (a*a) > (b*b) + (c*c) ){
        printf("TRIANGULO OBTUSANGULO\n");
    }else if ( (a*a) < (b*b) + (c*c) ){
        printf("TRIANGULO ACUTANGULO\n");
    }
    //identifica quanto aos lados.
    if ( (a == b && b != c) || (a != b && b == c) || (a == c && c != b) ){
        printf("TRIANGULO ISOSCELES\n");
    }else if (a == b && b == c){
        printf("TRIANGULO EQUILATERO\n");
    }

    return 0;
}
