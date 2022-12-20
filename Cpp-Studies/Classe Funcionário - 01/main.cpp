#include <iostream>
#include "Funcionario.h"

using namespace std;

int main(){
    int n, i;

    cin >> n;
    cin.ignore();
    Funcionario funcs[n];

    for (i = 0; i < n; i++){
        getline(cin, funcs[i].nome);
        getline(cin, funcs[i].sobrenome);
        cin >> funcs[i].salario;
        cin.ignore();
        cout << funcs[i].nome << " " << funcs[i].sobrenome
             << " - " << funcs[i].salario
             << " - " << funcs[i].getSalarioAnual() << endl;
    }

    return 0;
}
