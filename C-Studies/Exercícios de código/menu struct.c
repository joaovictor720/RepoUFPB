/**
    Laboratorio de Introducao a Programacao para Engenharia da Computacao.
    Atividade do dia 21 de junho de 2021.

    Descricao:

    Complete esse codigo fonte para criar um programa dirigido por menus que mantem um
    cadastro de um tesouro e sua localizacao.

    O tesouro sera representado por:
      - Uma descricao (dinheiros, chocolate, feriado, ponto extra)
      - Um valor em reais
      - Uma coordenada X
      - Uma coordenada Y

    As funcionalidades do programa sao:
      - Cadastro do tesouro
      - Impressao das informacoes do tesouro cadastrado
      - Informar a distancia do tesouro a partir de um determinado ponto
        inserido pelo usuario

*/

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <math.h>

#define MAX_DESCRICAO 51

typedef struct {
    char descricao[MAX_DESCRICAO];
    float valor;
    int x;
    int y;
    }tRegistro;

void ApresentaMensagem() {
    printf("Ola, esse programa ira guardar os segredos do seu tesouro.. uau");
}

void ApresentaMenu() {
    printf("\n\n\n*** Opcoes *** \n"
                "\n1 - Cadastra"
                "\n2 - Imprime"
                "\n3 - Distancia a partir de um ponto"
                "\n5 - Sair"
                "\n\nEscolha - ");
}

tRegistro * CadastroRegistro(tRegistro *reg) {
    //ler do usuario e preencher, use prompts e scanf e preencha a estrutura no parametro
    printf("\n---Cadastrar---\n");

    printf("\nO que eh o seu tesouro: ");
    scanf("%s", reg->descricao);

    printf("Qual o valor em reais: ");
    scanf("%f", &reg->valor);

    printf("Insira a coordenada X: ");
    scanf("%d", &reg->x);
    printf("Insira a coordenada Y: ");
    scanf("%d", &reg->y);

    printf("\n<<TESOURO REGISTRADO>>");

    return reg;
}

void ImprimeRegistro(const tRegistro *reg) {
    //mostrar as informacoes do registro do parametro de forma organizada
    printf("\n---Informacoes---\n\n");

    printf("Descricao: %s\n", reg->descricao);
    printf("Valor: R$ %.2f\n", reg->valor);
    printf("Coordenadas: (%d, %d)", reg->x, reg->y);
}

float Distancia(tRegistro reg, int x, int y){
	//funcao q retorna a distancia da coordenada dos parametros ate a coordenada do registro
	return sqrt( (x-reg.x)*(x-reg.x) + (y-reg.y)*(y-reg.y) );
}

int main(void)
{
    int x, y;
    tRegistro reg; //guarda o registro
    int opcao;
    ApresentaMensagem();

    while(1){
        ApresentaMenu();
        scanf("%d", &opcao);

        if (opcao == 5){
            break;
        }

        switch(opcao){
            case 1:
                CadastroRegistro(&reg);
                break;
            case 2:
                ImprimeRegistro(&reg);
                break;
            case 3:
                printf("\nDigite as coordenadas de um ponto...\n");

                printf("Coordenada X: ");
                scanf("%d", &x);
                printf("Coordenada Y: ");
                scanf("%d", &y);

                printf("\nDistancia do ponto (%d, %d) ate o tesouro: %.2f unidades", x, y, Distancia(reg, x, y));
                break;
            default:
                puts("Opcao Invalida\n");
                break;
        }
    }

    puts("Adeus");
    return 0;
}
