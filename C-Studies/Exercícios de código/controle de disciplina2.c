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


int nAlunos, ficouRecup[MAX_ALUNOS];
float mediaDefinitiva;
char disciplina[SIZE_DISCIPLINA];
tipo_discente discentes[MAX_ALUNOS];


void TiraNL(char *str){
    str[strlen(str)-1] = '\0';
}

float MediaFinal(tipo_discente *reg){
    return (  reg->media*6 + reg->recup*4 ) / 10;
}

void ExibeRelatorio(tipo_discente *aluno, int i){
    printf("%05d\t\t%s\t\t%.1f\t%.1f\t%.1f\t", aluno->matricula, aluno->nome, aluno->nota1, aluno->nota2, aluno->nota3);

    aluno->recup == 0? printf("-\t") : printf("%.1f\t", aluno->recup);

    if (ficouRecup[i]){
        mediaDefinitiva = MediaFinal(aluno);
    }else{
        mediaDefinitiva = aluno->media;
    }

    printf("%.1f\t", mediaDefinitiva);

    if (aluno->media >= 7 || mediaDefinitiva >= 5){
        printf("Aprovado\n");
    }else if (aluno->media < 4 || mediaDefinitiva < 5){
        printf("Reprovado\n");
    }
}

void RegistraRecup(tipo_discente *aluno){
    printf("O aluno [%s] obteve a media %.2f, por isso ele ficou de recuperacao :(\n", aluno->nome, aluno->media);
    printf("Qual foi a nota de recuperacao dele: ");
    scanf("%f", &aluno->recup);
}

void RegistraNotas(tipo_discente *aluno){
    printf("Digite as notas de [%s]\n", aluno->nome);

    printf("Nota 1: ");
    scanf("%f", &aluno->nota1);
    printf("Nota 2: ");
    scanf("%f", &aluno->nota2);
    printf("Nota 3: ");
    scanf("%f", &aluno->nota3);

    printf("\n");
}

void RegistraAluno(tipo_discente *aluno, int i){
    printf("Matricula do aluno %d: ", i+1);
    scanf("%d%*c", &aluno->matricula);

    printf("Nome do aluno %d: ", i+1);
    fgets(aluno->nome, SIZE_NOME, stdin);
    TiraNL(aluno->nome);

    printf("\n");
}

void CarregaEntrada(){
    FILE *fp;
    char entrada[51];
    int i;

    printf("Digite o nome do arquivo de entrada(insira .txt no final): \n");
    scanf("%s", &entrada);

    fp = fopen(entrada, "rt");
    printf("\nCarregando arquivo...\n");
    if (fp == NULL){
        printf("Erro ao abrir o arquivo de entrada.\n");
        return;
    }

    fgets(disciplina, SIZE_DISCIPLINA, fp);
    TiraNL(disciplina);

    fscanf(fp, "%d%*c", &nAlunos);

    for (i = 0; i < nAlunos; i++){
        fscanf(fp, "%d%*c", &discentes[i].matricula);
        fgets(discentes[i].nome, SIZE_NOME, fp);
        TiraNL(discentes[i].nome);

        //zerando as recuperações por enquanto
        discentes[i].recup = 0;
    }

    for (i = 0; i < nAlunos; i++){
        fscanf(fp, "%f", &discentes[i].nota1);
        fscanf(fp, "%f", &discentes[i].nota2);
        fscanf(fp, "%f", &discentes[i].nota3);
    }

    for (i = 0; i < nAlunos; i++){
        discentes[i].media = (discentes[i].nota1 + discentes[i].nota2 + discentes[i].nota3) / 3;

        if (4 < discentes[i].media && discentes[i].media < 7){
            fscanf(fp, "%f", &discentes[i].recup);
            ficouRecup[i] = 1;
        }
    }
    printf("Arquivo de entrada carregado com sucesso.\n");
    fclose(fp);
}

void SalvaRelatorio(){
    FILE *fp;

    fp = fopen("relatorio.txt", "wt");
    printf("\nSalvando relatorio...\n");
    if (fp == NULL){
        printf("Erro ao criar o arquivo de relatorio.\n");
        return;
    }

    fprintf(fp, "Disciplina: %s\n", disciplina);
    fprintf(fp, "----------------------------------------------------------------------------------------\n"
                "Matrícula\tNome\t\t\tNota1\tNota2\tNota3\tRecup\tMédia\tSituação\n"
                "----------------------------------------------------------------------------------------\n");
    for (int i = 0; i < nAlunos; i++){
        fprintf(fp, "%d\t\t%s\t\t%.1f\t%.1f\t%.1f\t", discentes[i].matricula, discentes[i].nome, discentes[i].nota1, discentes[i].nota2, discentes[i].nota3);

        discentes[i].recup == 0? fprintf(fp, "-\t") : fprintf(fp, "%.1f\t", discentes[i].recup);

        if (ficouRecup[i]){
            mediaDefinitiva = MediaFinal(&discentes[i]);
        }else{
            mediaDefinitiva = discentes[i].media;
        }

        fprintf(fp, "%.1f\t", mediaDefinitiva);

        if (discentes[i].media >= 7 || mediaDefinitiva >= 5){
            fprintf(fp, "Aprovado\n");
        }else if (discentes[i].media < 4 || mediaDefinitiva < 5){
            fprintf(fp, "Reprovado\n");
        }
    }
    printf("Relatorio salvo com sucesso.\n");
}

int main(void){
    int i, opcao;

    printf("[==============================================]\n"
           " Seja bem-vindo(a) ao Controlador de Disciplina\n"
           "[==============================================]\n");

    printf("Escolha qual o modo de funcionamento do programa:\n");
    printf("(0) para usuario, (1) para arquivo\n");
    scanf("%d%*c", &opcao);

    if (opcao){
        CarregaEntrada();
        SalvaRelatorio();
        return 0;
    }

    puts("\nQual disciplina iremos cadastrar hoje: ");
    fgets(disciplina, SIZE_DISCIPLINA, stdin);
    TiraNL(disciplina);

    puts("\nQuantos alunos tem essa disciplina: ");
    scanf("%d", &nAlunos);

    printf("\n[==============================================]\n\n");
    for (i = 0; i < nAlunos; i++){
        RegistraAluno(&discentes[i], i);

        //zerando as recuperações por enquanto
        discentes[i].recup = 0;
    }

    printf("[==============================================]\n\n");
    for (i = 0; i < nAlunos; i++){
        RegistraNotas(&discentes[i]);
    }

    printf("[==============================================]\n\n");
    for (i = 0; i < nAlunos; i++){
        discentes[i].media = (discentes[i].nota1 + discentes[i].nota2 + discentes[i].nota3) / 3;

        if (4 < discentes[i].media && discentes[i].media < 7){
            RegistraRecup(&discentes[i]);
            ficouRecup[i] = 1;
        }
    }

    printf("\nDisciplina: %s\n", disciplina);
    printf("----------------------------------------------------------------------------------------\n"
           "Matricula\tNome\t\t\tNota1\tNota2\tNota3\tRecup\tMedia\tSituacao\n"
           "----------------------------------------------------------------------------------------\n");
    for (i = 0; i < nAlunos; i++){
        ExibeRelatorio(&discentes[i], i);
    }

    return 0;
}
