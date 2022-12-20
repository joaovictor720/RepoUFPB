#include <stdio.h>

#define LINHAS 1000
#define COLUNAS 61

int Unir(int matriz[][COLUNAS], int conj1, int conj2, int sizeL, int sizeC, int tamanhoConj[]){
    int i, j, cont = 0;

    //for's para ver quantos elementos s�o diferentes entre os conjuntos(linhas da matriz)
    for (i = 0; i < sizeL; i++){
        for (j = 0; j < sizeC; j++){

            //esse if pega um elemento da linha 'conj1' e v� quais s�o diferentes em outra linha 'conj2'
            //o -1 nos conj � um shift, pois o usu�rio insere como posi��o e n�o em �ndice, ou seja, conj>=1
            if (matriz[conj1-1][i] != matriz[conj2-1][j]){
                if (matriz[conj1-1][i] != 0 && matriz[conj2-1][j] != 0){
                    cont++;
                }
            }
        }
    }

    //somar o contador com tamanho da menor linha, ou seja, do menor conjunto
    if (tamanhoConj[conj1-1] > tamanhoConj[conj2-1]){
        return cont+tamanhoConj[conj2-1];
    }else{
        return cont+tamanhoConj[conj1-1];
    }
}

int Intersetar(int matriz[][COLUNAS], const int conj1, const int conj2, int sizeL, int sizeC){
    int i, j, cont = 0;

    for (i = 0; i < sizeL; i++){
        for (j = 0; j < sizeC; j++){

            //esse if pega um elemento da linha 'conj1' e v� quais s�o iguais em outra linha 'conj2'
            //o -1 nos conj � um shift, pois o usu�rio insere como posi��o e n�o em �ndice, ou seja, conj>=1
            if (matriz[conj1-1][i] == matriz[conj2-1][j]){
                if (matriz[conj1-1][i] != 0 && matriz[conj2-1][j] != 0){
                    cont++;
                }
            }
        }
    }

    return cont;
}

void ZeraMatriz(int matriz[][COLUNAS], int I, int J){
    int i, j;

    for (i = 0; i < I; i++){
        for (j = 0; j < J; j++){
            matriz[i][j] = 0;
        }
    }
}

int main(void){
    int T, i, j, incr1, incr2, cont; //vari�veis para incrementa��o
    int Lin, nOp, Op, conj1, conj2; //vari�veis para l�gica do programa

    scanf("%d", &T);

    for (incr1 = 0; incr1 < T; incr1++){
        scanf("%d", &Lin);

        int matriz[LINHAS][COLUNAS], Col[LINHAS];

        ZeraMatriz(matriz, LINHAS, COLUNAS);

        //preenchimento da matriz
        //cada linha � preenchida at� C, o resto � 0
        for (i = 0; i < Lin; i++){
            scanf("%d", &Col[i]);

            for (j = 0; j < Col[i]; j++){
                scanf("%d", &matriz[i][j]);
            }
        }

        //debug para mostrar toda a matriz j� preenchida
        for (i = 0; i < LINHAS; i++){
            puts("");
            printf("%d", Col[i]);
            for (j = 0; j < COLUNAS; j++){
                printf("\t%d", matriz[i][j]);
            }
        }
        puts("");
        scanf("%d", &nOp);

        for (incr2 = 0; incr2 < nOp; incr2++){
            scanf("%d %d %d", &Op, &conj1, &conj2);

            switch (Op){
                case 1://interse��o
                    cont = Intersetar(matriz, conj1, conj2, LINHAS, COLUNAS);
                    printf("%d\n", cont);
                    break;
                case 2://uni�o
                    cont = Unir(matriz, conj1, conj2, LINHAS, COLUNAS, Col);
                    printf("%d\n", cont);
                    break;
            }
        }
    }

    return 0;
}
