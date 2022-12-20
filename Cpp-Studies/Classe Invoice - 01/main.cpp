#include <iostream>
#include <Invoice.h>

using namespace std;

int main()
{
    Invoice inv[2];

    for (int i = 0; i < 2; i++){
        cin >> inv[i].numero;
        if (inv[i].numero < 0){
            inv[i].numero = 0;
        }
        cin.ignore();
        getline(cin, inv[i].descricao);
        cin >> inv[i].qtd
            >> inv[i].preco;
        if (inv[i].qtd < 0){
            inv[i].qtd = 0;
        }
        if (inv[i].preco < 0.0){
            inv[i].preco = 0.0;
        }
    }

    for (int i = 0; i < 2; i++){
        cout << inv[i].numero << " - "
             << inv[i].descricao << " - "
             << inv[i].qtd << " - "
             << inv[i].preco << " - "
             << inv[i].getInvoiceAmount() << endl;
    }

    return 0;
}
