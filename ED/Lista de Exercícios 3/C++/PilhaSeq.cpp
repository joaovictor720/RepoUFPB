#include "PilhaSeq.h"

PilhaSeq::PilhaSeq(){
    topo = -1;
}

/*
PilhaSeq::PilhaSeq(const int n){
    int dadosAux[n];
    dados = dadosAux;
    topo = -1;
}
*/
PilhaSeq::~PilhaSeq(){}

bool PilhaSeq::vazia(){
    if (topo == -1)
        return true;
    else 
        return false;
}

/**Verifica se a Pilha está cheia */
bool PilhaSeq::cheia(){
    int size = sizeof(dados)/sizeof(dados[0]);
    if (topo == (size))
        return true;
    else
        return false;
}

/**Obtém o tamanho da Pilha*/
int PilhaSeq::tamanho(){
    return topo+1;
}

/** Consulta o elemento do topo da Pilha.
    Retorna -1 se a pilha estiver vazia, 
    caso contrário retorna o valor que está no topo da pilha. */
int PilhaSeq::top() {
    if (vazia()) 
        return -1; // pilha vazia

    return dados[topo];
}

/** Insere um elemento no topo da pilha.
    Retorna false se a pilha estiver cheia. 
    Caso contrário retorna true */
bool PilhaSeq::push(int valor) {
    if (cheia()) 
        return false;  // err: pilha cheia
    topo++;
    dados[topo] = valor;
    return true;
}   

/** Retira o elemento do topo da pilha.
    Retorna -1 se a pilha estiver vazia. */
int PilhaSeq::pop() {          
    if (vazia()) 
        return -1; // Pilha vazia

    int valor = dados[topo]; 
    topo--; 
    return valor;
}

int PilhaSeq::menor(){
    int menor = 999999999;
    int aux;
    while (tamanho() > 0){
        aux = this->pop();
        if (aux < menor){
            menor = aux;
        }
    }
    return menor;
}