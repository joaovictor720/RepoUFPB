#include <iostream>
#include <string>
using namespace std;

int main (void){
    float salario = -1, emp = -1, nPrest = -1;
    float aux;

    while (1){
        cin >> aux;
        if (aux < 0){
            continue;
        }
        if (salario > 0){
            if (emp > 0){
                if (nPrest < 0){
                    nPrest = aux;
                    break;
                }
            }else{
                emp = aux;
                continue;
            }
        }else{
            salario = aux;
            continue;
        }
    }

    if (emp / nPrest > 0.3*salario){
        cout << "Emprestimo nao pode ser concedido" << endl;
    }else{
        cout << "Emprestimo pode ser concedido" << endl;
    }

    return 0;
}
