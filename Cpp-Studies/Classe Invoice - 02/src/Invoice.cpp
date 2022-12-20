#include "Invoice.h"

Invoice::Invoice()
{
    numero = 0;
    qtd = 0;
    preco = 0.0;
}

void Invoice::print(){
    std::cout << getNumero() << " - "
         << getDescricao() << " - "
         << getQtd() << " - "
         << getPreco() << " - "
         << getInvoiceAmount() << std::endl; // mesma linha tudo
}

void Invoice::setNumero(int num){
    numero = num;
}

void Invoice::setDescricao(std::string desc){
    descricao = desc;
}

void Invoice::setQtd(int quantidade){
    qtd = quantidade;
}

void Invoice::setPreco(float preco){
    this->preco = preco;
}

int Invoice::getNumero(){
    return numero;
}

std::string Invoice::getDescricao(){
    return descricao;
}

int Invoice::getQtd(){
    return qtd;
}

float Invoice::getPreco(){
    return preco;
}

float Invoice::getInvoiceAmount(){
    return qtd * preco;
}
