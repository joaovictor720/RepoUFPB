#include <iostream>
#include <string>
using namespace std;

int main (void){
    int N, i;

    cin >> N; // definindo tamanho do vetor
    int vet[N];

    for (i = 0; i < N; i++){
        cin >> vet[i]; // preenchendo vetor
    }

    // busca bin�ria do elemento i com todos os seguintes
    // se achar um igual, zera
    for (i = 0; i < N; i++){
        for (int j = i+1; j < N; j++){
            if (vet[i] == vet[j]){
                vet[j] = 0;
            }
        }
    }

    // exibindo os elementos positivos, com espa�o
    for (i = 0; i < N; i++){
        if (vet[i] != 0){
            cout << vet[i] << " ";
        }
    }

    return 0;
}
