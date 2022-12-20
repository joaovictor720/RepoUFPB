#include <iostream>
#include <string>
#include <math.h>

using namespace std;

#define TAM_MAX 100

class PilhaSeq{
    private:
        unsigned long dados[TAM_MAX];
        int topo;
        unsigned long menor;

    public:
        PilhaSeq(){
            topo = -1;
            menor = -1;
        }
        //PilhaSeq(int n)
        virtual ~PilhaSeq(){}

        bool vazia(){
            if (topo == -1)
                return true;
            else 
                return false;
        }
        
        /**Verifica se a Pilha está cheia */
        bool cheia(){
            int size = sizeof(dados)/sizeof(dados[0]);
            if (topo == (size))
                return true;
            else
                return false;
        }
        
        /**Obtém o tamanho da Pilha*/
        int tamanho(){
            return topo+1;
        }
        
        /** Consulta o elemento do topo da Pilha.
            Retorna -1 se a pilha estiver vazia, 
            caso contrário retorna o valor que está no topo da pilha. */
        int top() {
            if (vazia()) 
                return -1; // pilha vazia
        
            return dados[topo];
        }
        
        /** Insere um elemento no topo da pilha.
            Retorna false se a pilha estiver cheia. 
            Caso contrário retorna true */
        bool push(int valor) {
            if (cheia()) 
                return false;  // err: pilha cheia
            if (valor < this->menor)
                menor = valor;
            topo++;
            dados[topo] = valor;
            return true;
        }   

        /** Retira o elemento do topo da pilha.
            Retorna -1 se a pilha estiver vazia. */
        int pop() {          
            if (vazia()) 
                return -1; // Pilha vazia

            int valor = dados[topo]; 
            if (valor == this->menor)

            topo--; 
            return valor;
        }
        
        unsigned long menorReduzindo(){
            unsigned long menorReduzindo = pow(2, sizeof(unsigned long));
            unsigned long aux;
            while (tamanho() > 0){
                aux = this->pop();
                if (aux < menorReduzindo){
                    menorReduzindo = aux;
                }
            }
            return menorReduzindo;
        }
};

int main(void){
    PilhaSeq pilha = PilhaSeq();
    PilhaSeq pilhaAux = pilha;
    int nOp;
    string operacao;
    int operando;
    
    cin >> nOp;
    cin.ignore();
    
    for (int i = 0; i < nOp; i++){
        cin >> operacao;
        if (operacao == "PUSH")
            cin >> operando;

        pilhaAux = pilha;
        if (operacao == "PUSH"){
            pilha.push(operando);
        } else if (operacao == "POP"){
            if (pilha.vazia()){
                cout << "EMPTY" << endl;
                continue;
            }
            pilha.pop();
        } else if (operacao == "MIN"){
            if (pilha.vazia()){
                cout << "EMPTY" << endl;
                continue;
            }
            unsigned long menor = pilhaAux.menorReduzindo();
            cout << menor << endl;
        } else {
            cout << "Entrada invalida" << endl;
        }
    }

    return 0;
}