#include <iostream>
#include "Pessoa.h"

using namespace std;

int main()
{
    Pessoa pessoas[2];

    for (int i = 0; i < 2; i++){
        getline(cin, pessoas[i].nome);
        cin >> pessoas[i].idade;
        cin.ignore();
        getline(cin, pessoas[i].telefone);
    }

    for (int i = 0; i < 2; i++){
        cout << pessoas[i].nome << ", "
             << pessoas[i].idade << ", "
             << pessoas[i].telefone << endl;
    }

    return 0;
}
