/******************************************************
*Olá, passei 2 dias tentando adaptar o código antigo  *
*do primeiro exercício, mas simplesmente não achei    *
*uma forma que fizesse sentido, tanto para o primeiro *
*programa, quanto para o carregamento e salvamento de *
*arquivos binários. Nesse caso, as funções de arquivo *
*binário até funcionam, eu acredito, mas como agora já*
*são 23:06, e eu já refleti bastante sobre como imple-*
*mentar, e não sobraram mais neurônios para isso, eu  *
*venho aqui admitir que desisti de fazer um programa  *
*satisfatório para mim.                               *
******************************************************/

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
static char disciplina[SIZE_DISCIPLINA];
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

void CarregaTexto(){
    FILE *fp;
    char entrada[51];
    int i;

    printf("\nDigite o nome do arquivo de entrada(insira .txt no final): \n");
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

void SalvaTexto(){
    FILE *fp;

    fp = fopen("relatorio.txt", "wt");
    printf("\nSalvando relatorio em texto...\n");
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

void CarregaBin(){
    FILE *fp;
    char entrada[51];
    int i;

    printf("\nDigite o nome do arquivo de entrada(insira .bin ou .dat no final): \n");
    scanf("%s", &entrada);

    fp = fopen(entrada, "rb");
    printf("\nCarregando arquivo...\n");
    if (fp == NULL){
        printf("Erro ao abrir o arquivo de entrada.\n");
        return;
    }

    i = 0;
    while(1){
        fread(&discentes[i], sizeof(tipo_discente), 1, fp);
        if (feof(fp)){
            break;
        }
        i++;
    }

    /*fread(disciplina, sizeof(char), SIZE_DISCIPLINA, fp);
    printf("disciplina = %s\n", disciplina);

    fread(&nAlunos, sizeof(int), 1, fp);
    printf("nAlunos = %d\n", nAlunos);

    for (i = 0; i < nAlunos; i++){
        printf("debug1\n");
        fread(&discentes[i].matricula, sizeof(int), 1, fp);
        fread(&discentes[i].nome, sizeof(char), SIZE_NOME, fp);
        printf("debug2\n");

        //zerando as recuperações por enquanto
        discentes[i].recup = 0;
    }

    for (i = 0; i < nAlunos; i++){
        fread(&discentes[i].nota1, sizeof(float), 1, fp);
        fread(&discentes[i].nota2, sizeof(float), 1, fp);
        fread(&discentes[i].nota3, sizeof(float), 1, fp);
    }

    for (i = 0; i < nAlunos; i++){
        discentes[i].media = (discentes[i].nota1 + discentes[i].nota2 + discentes[i].nota3) / 3;

        if (4 < discentes[i].media && discentes[i].media < 7){
            fread(&discentes[i].recup, sizeof(float), 1, fp);
            ficouRecup[i] = 1;
        }
    }*/
    printf("Arquivo de entrada carregado com sucesso.\n");
    fclose(fp);
}

void SalvaBin(){
    FILE *fp;
    char newLine[] = "\n", space[] = " ";
    int i;

    fp = fopen("relatorio.bin", "wb");
    printf("\nSalvando relatorio binario...\n");
    if (fp == NULL){
        printf("Erro ao criar o arquivo de relatorio.\n");
        return;
    }

    for (i = 0; i < nAlunos; i++){
        fwrite(&discentes[i], sizeof(tipo_discente), 1, fp);
    }
    /*fwrite(disciplina, sizeof(char), SIZE_DISCIPLINA, fp);
    fwrite(newLine, sizeof(char), strlen(newLine), fp);

    fwrite(&nAlunos, sizeof(int), 1, fp);
    fwrite(newLine, sizeof(char), strlen(newLine), fp);

    for (i = 0; i < nAlunos; i++){
        fwrite(&discentes[i].matricula, sizeof(int), 1, fp);
        fwrite(newLine, sizeof(char), strlen(newLine), fp);

        fwrite(&discentes[i].nome, sizeof(char), SIZE_NOME, fp);
        fwrite(newLine, sizeof(char), strlen(newLine), fp);
    }

    for (i = 0; i < nAlunos; i++){
        fwrite(&discentes[i].nota1, sizeof(float), 1, fp);
        fwrite(space, sizeof(char), strlen(space), fp);

        fwrite(&discentes[i].nota2, sizeof(float), 1, fp);
        fwrite(space, sizeof(char), strlen(space), fp);

        fwrite(&discentes[i].nota3, sizeof(float), 1, fp);
        fwrite(newLine, sizeof(char), strlen(newLine), fp);
    }

    for (i = 0; i < nAlunos; i++){
        discentes[i].media = (discentes[i].nota1 + discentes[i].nota2 + discentes[i].nota3) / 3;

        if (4 < discentes[i].media && discentes[i].media < 7){
            fwrite(&discentes[i].recup, sizeof(float), 1, fp);
            fwrite(newLine, sizeof(char), strlen(newLine), fp);
        }
    }*/
    printf("Relatorio salvo com sucesso.\n");
    fclose(fp);
}

int main(void){
    int i, opcaoModo, opcaoArq, opcaoCriar;

    printf("[==============================================]\n"
           " Seja bem-vindo(a) ao Controlador de Disciplina\n"
           "[==============================================]\n");

    printf("\nEscolha qual o modo de funcionamento do programa:\n");
    printf("(0) para usuario, (1) para arquivo\n");
    scanf("%d%*c", &opcaoModo);

    if (opcaoModo){
        printf("\nEscolha qual o tipo de arquivo a ser carregado:\n");
        printf("(0) para binario, (1) para texto\n");
        scanf("%d", &opcaoArq);
        if (opcaoArq){
            CarregaTexto();
            printf("\nO que deseja fazer com o arquivo carregado\n");
            printf("(0) para salvar em binario, (1) exibir na tela, (2) para ambos\n");
            scanf("%d", &opcaoArq);
            switch (opcaoArq){
                case 0:
                    SalvaBin();
                    break;
                case 1:
                    for (i = 0; i < nAlunos; i++){
                        ExibeRelatorio(&discentes[i], i);
                    }
                    break;
                case 2:
                    SalvaBin();
                    for (i = 0; i < nAlunos; i++){
                        ExibeRelatorio(&discentes[i], i);
                    }
                    break;
                default:
                    printf("Opcao invalida.\n");
            }
            return 0;
        }else{
            CarregaBin();
            printf("\n\nExibindo relatorio...\n\n");

            printf("\nDisciplina: %s\n", disciplina);
            printf( "----------------------------------------------------------------------------------------\n"
                    "Matricula\tNome\t\t\tNota1\tNota2\tNota3\tRecup\tMedia\tSituacao\n"
                    "----------------------------------------------------------------------------------------\n");
            for (i = 0; i < nAlunos; i++){
                ExibeRelatorio(&discentes[i], i);
            }
            return 0;
        }
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

    printf("\nVoce deseja criar um relatorio em arquivo: \n");
    printf("(0) para NAO, (1) para SIM\n");
    scanf("%d", &opcaoCriar);
    if (opcaoCriar){
        printf("\nQual tipo: \n");
        printf("(0) para texto, (1) para binario, (2) para ambos\n");
        scanf("%d", &opcaoCriar);
        switch (opcaoCriar){
            case 0:
                SalvaTexto();
                break;
            case 1:
                SalvaBin();
                break;
            case 2:
                SalvaTexto();
                SalvaBin();
                break;
            default:
                printf("Opcao invalida.\n");
        }
    }

    return 0;
}
