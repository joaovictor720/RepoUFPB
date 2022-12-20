#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_DISCENTE 60
#define MAX_NOME 31
#define MAX_MATRICULA 16

int qDiscentes = 0;

typedef struct {
    char nome[MAX_NOME];
    char matricula[MAX_MATRICULA];
    float nota1, nota2;
    } tDiscente;

tDiscente discente[MAX_DISCENTE];

void RemoveBarraN(char *str){
    if (str[strlen(str)-1] == '\n'){
        str[strlen(str)-1] = '\0';
    }
}

float Media(float v1, float v2){
    return (v1 + v2) / 2;
}

void CarregaDados(){
    FILE *fp;
    char str[101];

    fp = fopen("notas.dat", "r");
    if (fp == NULL){
        printf("Erro ao abrir o arquivo de dados.\n");
        return;
    }

    while(1){
        fgets(str, 101, fp);
        if (feof(fp))
            break;
        RemoveBarraN(str);
        strcpy(discente[qDiscentes].matricula, str);
        fgets(str, 101, fp);
        RemoveBarraN(str);
        strcpy(discente[qDiscentes].nome, str);
        fscanf(fp, "%f %f%*c", &discente[qDiscentes].nota1, &discente[qDiscentes].nota2);
        qDiscentes++;
    }

    if (fclose(fp) == 0){
        printf("Dados carregados com sucesso.\n");
    }
}

void RelatorioEmArquivo(const char *arq){
    int i;
    FILE *fp;

    fp = fopen(arq, "w");
    if (fp == NULL){
        printf("Erro ao criar o arquivo de relatorio \"%s\".\n", arq);
        return;
    }

    fprintf(fp, "\n--------------------------------------------------------------------\n");
    fprintf(fp, " Matricula\tNome\t\t\tNota 1\tNota 2\tMedia\n");
    fprintf(fp, "--------------------------------------------------------------------\n");

    for(i = 0; i < qDiscentes; i++){
        fprintf(fp, " %s\t\t%s\t\t%.1f\t%.1f\t%.1f\n", discente[i].matricula, discente[i].nome,
                discente[i].nota1, discente[i].nota2, Media(discente[i].nota1, discente[i].nota2));
    }

    fprintf(fp, "--------------------------------------------------------------------\n");

    if (fclose(fp) == 0){
        printf("Relatorio criado no arquivo \"%s\".\n", arq);
    }
}

void SalvaDados(){
    int i;
    FILE *fp;

    fp = fopen("notas.dat", "w");
    if (fp == NULL){
        printf("Erro ao criar o arquivo de dados.\n");
        return;
    }
    for(i = 0; i < qDiscentes; i++){
        fprintf(fp, "%s\n%s\n%f %f\n", discente[i].matricula, discente[i].nome, discente[i].nota1, discente[i].nota2);
    }

    if (fclose(fp) == 0){
        printf("Dados salvos com sucesso.\n");
    }
}

void ExibeMenu(){
    printf("\n----------- Menu -----------\n"
           "1 - Cadastrar discente\n"
           "2 - Cadastrar notas\n"
           "3 - Consultar discente\n"
           "4 - Relatorio de notas\n"
           "5 - Atualiza notas\n"
           "6 - Ordena\n"
           "7 - Relatorio em arquivo\n"
           "8 - Salvar dados\n"
           "9 - Carregar dados\n"
           "10 - Sair\n\n");
}

void AdicionaDiscente(){
    if (qDiscentes >= MAX_DISCENTE){
        puts("Capacidade de armazenamento cheia.");
        return;
    }

    printf("Insira as informacoes do discente #%d: \n", qDiscentes + 1);
    printf("\tMatricula: ");
    scanf("%s%*c", discente[qDiscentes].matricula);
    printf("\tNome: ");
    fgets(discente[qDiscentes].nome, MAX_NOME, stdin);
    RemoveBarraN(discente[qDiscentes].nome);
    qDiscentes++;
}

void CadastraNotas(){
    int i;

    for(i = 0; i < qDiscentes; i++){
        printf("\nNotas do discente %s (%s):\n", discente[i].nome, discente[i].matricula);
        printf("\tNota 1: ");
        scanf("%f", &discente[i].nota1);
        printf("\tNota 2: ");
        scanf("%f", &discente[i].nota2);
    }
}

int ProcuraMatricula(const char *chave){
    int i;

    for(i = 0; i < qDiscentes; i++){
        if ( strcmp(chave, discente[i].matricula ) == 0 )
            return i;
    }

    return -1;
}

int ProcuraNome(const char *chave){
    int i;

    for(i = 0; i < qDiscentes; i++){
        if ( strstr(discente[i].nome, chave) != NULL )
            return i;
    }

    return -1;
}

void ExibeDiscente(int i){
    printf("Informacoes do discente #%d:\n", i+1);
    printf("\tMatricula: %s\n", discente[i].matricula);
    printf("\tNome: %s\n", discente[i].nome);
    printf("\tNota 1: %.1f\n", discente[i].nota1);
    printf("\tNota 2: %.1f\n", discente[i].nota2);
}

/*
    opcao 0 = matricula
    opcao 1 = nome
*/
void ConsultaDiscente(int opcao){
    char chave[MAX_NOME];
    int i;

    printf("Digite a chave de pesquisa: ");
    fgets(chave, MAX_NOME, stdin);
    RemoveBarraN(chave);

    if (opcao == 0){
        i = ProcuraMatricula(chave);
    }else{
        i = ProcuraNome(chave);
    }

    if (i >= 0){
        ExibeDiscente(i);
    }else{
        puts("Discente nao encontrade.");
    }
}

void Relatorio(){
    int i;

    printf("\n--------------------------------------------------------------------\n");
    printf(" Matricula\tNome\t\t\tNota 1\tNota 2\tMedia\n");
    printf("--------------------------------------------------------------------\n");

    for(i = 0; i < qDiscentes; i++){
        printf(" %s\t\t%s\t\t%.1f\t%.1f\t%.1f\n", discente[i].matricula, discente[i].nome,
                discente[i].nota1, discente[i].nota2, Media(discente[i].nota1, discente[i].nota2));
    }

    printf("--------------------------------------------------------------------\n");
}

void AtualizaNota(){
    char chave[MAX_MATRICULA];
    int i;

    printf("Digite a matricula: ");
    fgets(chave, MAX_MATRICULA, stdin);
    RemoveBarraN(chave);

    i = ProcuraMatricula(chave);
    if (i == -1){
        puts("Matricula nao encontrada.");
        return;
    }

    ExibeDiscente(i);
    printf("Digite nova Nota 1: ");
    scanf("%f", &discente[i].nota1);
    printf("Digite nova Nota 2: ");
    scanf("%f", &discente[i].nota2);
}

void OrdenaNome(){
    int i, trocou;
    tDiscente aux;

    trocou = 1;
    while(trocou){
        trocou = 0;
        for(i = 0; i < qDiscentes-1; i++){
            if ( strcmp(discente[i].nome, discente[i+1].nome) > 0 ){
                aux = discente[i];
                discente[i] = discente[i+1];
                discente[i+1] = aux;
                trocou = 1;
            }
        }
    }

}

int main(void){
    int opcao;
    int tipoBusca;
    char arq[31];

    while(1){
        ExibeMenu();
        printf("Digite a opcao: ");
        scanf("%d%*c", &opcao);

        if (opcao == 10)
            break;

        switch(opcao){
            case 1:
                AdicionaDiscente();
                break;
            case 2:
                CadastraNotas();
                break;
            case 3:
                printf("Digite (0) para procurar por matricula ou (1) por nome: ");
                scanf("%d%*c", &tipoBusca);
                ConsultaDiscente(tipoBusca);
                break;
            case 4:
                Relatorio();
                break;
            case 5:
                AtualizaNota();
                break;
            case 6:
                OrdenaNome();
                break;
            case 7:
                printf("Digite o nome do arquivo para criacao do relatorio: ");
                scanf("%s", arq);
                RelatorioEmArquivo(arq);
                break;
            case 8:
                SalvaDados();
                break;
            case 9:
                CarregaDados();
                break;
            default:
                puts("Opcao invalida.");
        }
    }

    return 0;
}
