#include <iostream>
#include <vector>

using namespace std;

void mostrarLista(vector<int> lista, string tipoDaLista){
    for (int j = 0; j < lista.size(); j++){
        cout << tipoDaLista << "[" << j << "] = " << lista.at(j) << endl;
    }
}

void DEBUG(int temp, string tipoDaLista){
    cout << "colocando " << temp << " na lista " << tipoDaLista << endl;
}

int main(void){

    int temp;
    vector<int> listaPar, listaImpar;

    for (int i = 0; i < 15; i++){
        cin >> temp;
        if ( (temp % 2 == 0) ){
            if (listaPar.size() >= 5){
                mostrarLista(listaPar, "par");
                listaPar.resize(0);
            }
            listaPar.push_back(temp);
        } else {
            if (listaImpar.size() >= 5){
                mostrarLista(listaImpar, "impar");
                listaImpar.resize(0);
            }
            listaImpar.push_back(temp);
        }
    }

    mostrarLista(listaImpar, "impar");
    mostrarLista(listaPar, "par");

    cin >> temp;

    return 0;
}