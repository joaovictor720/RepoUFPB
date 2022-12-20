#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_DISCIPLINA 50
#define MAX_ALUNOS 30
#define SIZE_NOME 40

typedef struct {
    int matricula;
    char nome[SIZE_NOME];
    float nota1, nota2, nota3;
    float recup;
    float media;
    } tipo_discente;

void TiraNL(char *str){
    str[strlen(str)-1] = '\0';
}

float MediaFinal(tipo_discente reg){
    return ( ( (reg.media) * 6) + ( (reg.recup) * 4) ) / 10;
}

int main(void){
    char disciplina[SIZE_DISCIPLINA];
    int nAlunos, i, ficouRecup[MAX_ALUNOS] = {0};
    float mediaDefinitiva;
    tipo_discente discentes[MAX_ALUNOS];

    printf("[==============================================]\n"
           " Seja bem-vindo(a) ao Controlador de Disciplina\n"
           "[==============================================]\n");

    puts("\nQual disciplina iremos cadastrar hoje: ");
    fgets(disciplina, SIZE_DISCIPLINA, stdin);
    TiraNL(disciplina);

    puts("\nQuantos alunos tem essa disciplina: ");
    scanf("%d", &nAlunos);

    printf("\n[==============================================]\n\n");
    for (i = 0; i < nAlunos; i++){
        printf("Matricula do aluno %d: ", i+1);
        scanf("%d%*c", &discentes[i].matricula);

        printf("Nome do aluno %d: ", i+1);
        fgets(discentes[i].nome, SIZE_NOME, stdin);
        TiraNL(discentes[i].nome);
        printf("\n");

        //zerando as recuperações por enquanto
        discentes[i].recup = 0;
    }

    printf("\n[==============================================]\n\n");
    for (i = 0; i < nAlunos; i++){
        printf("Digite as notas de [%s]\n", discentes[i].nome);

        printf("Nota 1: ");
        scanf("%f", &discentes[i].nota1);
        printf("Nota 2: ");
        scanf("%f", &discentes[i].nota2);
        printf("Nota 3: ");
        scanf("%f", &discentes[i].nota3);

        printf("\n");
    }

    printf("\n[==============================================]\n\n");
    for (i = 0; i < nAlunos; i++){
        discentes[i].media = (discentes[i].nota1 + discentes[i].nota2 + discentes[i].nota3) / 3;

        if (4 < discentes[i].media && discentes[i].media < 7){
            printf("O aluno [%s] ficou com media %.2f, por isso ele ficou de recuperacao :(\n", discentes[i].nome, discentes[i].media);
            printf("Qual foi a nota de recuperacao dele: ");
            scanf("%f", &discentes[i].recup);

            ficouRecup[i] = 1;
        }
    }

    printf("\n\nDisciplina: %s\n", disciplina);
    printf("----------------------------------------------------------------------------------------\n"
           "Matricula\tNome\t\t\tNota1\tNota2\tNota3\tRecup\tMedia\tSituacao\n"
           "----------------------------------------------------------------------------------------\n");
    for (i = 0; i < nAlunos; i++){
        printf("%05d\t\t%s\t\t%.1f\t%.1f\t", discentes[i].matricula, discentes[i].nome, discentes[i].nota1, discentes[i].nota2);
        printf("%.1f\t", discentes[i].nota3);
        discentes[i].recup == 0? printf("-\t") : printf("%.1f\t", discentes[i].recup);

        if (ficouRecup[i]){
            mediaDefinitiva = MediaFinal(discentes[i]);
        }else{
            mediaDefinitiva = discentes[i].media;
        }

        printf("%.1f\t", mediaDefinitiva);

        if (discentes[i].media >= 7 || mediaDefinitiva >= 5){
            printf("Aprovado\n");
        }else if (discentes[i].media < 4 || mediaDefinitiva < 5){
            printf("Reprovado\n");
        }
    }

    return 0;
}
