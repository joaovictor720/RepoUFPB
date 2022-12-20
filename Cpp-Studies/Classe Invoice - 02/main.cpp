#include <iostream>
#include "Invoice.h"

using namespace std;

int main()
{
    Invoice inv[2];

    for (int i = 0; i < 2; i++){
        // variáveis temporárias para irem no métodos 'set'
        int num;
        string desc;
        int qtd;
        float preco;

        cin >> num;
        if (num < 0){
            num = 0; // se numero menor que zero, setar para zero
        }
        cin.ignore();
        inv[i].setNumero(num); // setando o atributo numero

        getline(cin, desc);
        inv[i].setDescricao(desc); // setando o atributo descrição

        cin >> qtd;
        if (qtd < 0){
            qtd = 0; // se quantidade menor que zero, setar para zero
        }
        inv[i].setQtd(qtd); // setando o atributo quantidade

        cin >> preco;
        if (preco < 0){
            preco = 0; // se preco menor que zero, setar para zero
        }
        inv[i].setPreco(preco); // setando o atributo preco
    }

    for (int i = 0; i < 2; i++){
        inv[i].print(); // exibindo os atributos
    }

    return 0;
}
