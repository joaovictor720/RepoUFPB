#include <stdio.h>

int main(void){
    float nt1, nt2, nt3, np1, np2, np3; //nt e np representam nota teórica e nota prática, respecivamente.
    float nu1, nu2, nu3, mFinal;        //nu representa nota unificada.
    float maiorP, menorP;               //essas variáveis representam maior peso e menor peso, respectivamente
                                        //por questões de manutenabilidade, criei as variáveis de peso, mesmo que nesse caso sejam fixas
    maiorP = 6;
    menorP = 4;

    printf("Insira sua primeira nota da materia teorica:\n");
    scanf("%f", &nt1);
    printf("Insira sua primeira nota da materia pratica:\n");
    scanf("%f", &np1);
    if (nt1 > np1){
        nu1 = ( (maiorP * nt1) + (menorP * np1) ) / (maiorP + menorP);
        printf("A sua primeira unidade tem media 1 = %.2f\n", nu1);
    }else{
        nu1 = ( (maiorP * np1) + (menorP * nt1) ) / (maiorP + menorP);
        printf("A sua primeira unidade tem media 1 = %.2f\n", nu1);
    }

    printf("\n\nInsira sua segunda nota da materia teorica:\n");
    scanf("%f", &nt2);
    printf("Insira sua segunda nota da materia pratica:\n");
    scanf("%f", &np2);
    if (nt2 > np2){
        nu2 = ( (maiorP * nt2) + (menorP * np2) ) / (maiorP + menorP);
        printf("A sua 2 unidade tem media = %.2f\n", nu2);
    }else{
        nu2 = ( (maiorP * np2) + (menorP * nt2) ) / (maiorP + menorP);
        printf("A sua 2 unidade tem media = %.2f\n", nu2);
    }

    printf("\n\nInsira sua 3 nota da materia teorica:\n");
    scanf("%f", &nt3);
    printf("Insira sua 3 nota da materia pratica:\n");
    scanf("%f", &np3);
    if (nt3 > np3){
        nu3 = ( (maiorP * nt3) + (menorP * np3) ) / (maiorP + menorP);
        printf("A sua 3 unidade tem media = %.2f\n", nu3);
    }else{
        nu3 = ( (maiorP * np3) + (menorP * nt3) ) / (maiorP + menorP);
        printf("A sua 3 unidade tem media = %.2f\n", nu3);
    }

    /*Os mFinal à esquerda são desnecessários, mas resolvi manter,
    para deixar visualmente mais fácil de identificar
    o fato de que representam intervalos*/

    mFinal = (nu1 + nu2 + nu3) / 3;
    printf("\n\nSua media final = %.2f\n", mFinal);
    if (mFinal < 5){
        printf("O Conceito da sua media eh F\n");
    }else if (5 <= mFinal && mFinal <= 6){
        printf("O Conceito da sua media eh E\n");
    }else if (6 <= mFinal && mFinal <= 7){
        printf("O Conceito da sua media eh D\n");
    }else if (7 <= mFinal && mFinal <= 8){
        printf("O Conceito da sua media eh C\n");
    }else if (8 <= mFinal && mFinal <= 9){
        printf("O Conceito da sua media eh B\n");
    }else if (9 <= mFinal && mFinal <= 10){
        printf("O Conceito da sua media eh A\n");
    }else{
        printf("\nEita teto, tirasse mais do que 10 foi boy, tu eh a febe tife neh. Ateh parece kkk\n");
        return 1;
    }

    return 0;
}
