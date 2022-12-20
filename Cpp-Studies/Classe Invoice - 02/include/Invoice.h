#ifndef INVOICE_H
#define INVOICE_H

#include <iostream>
#include <string>

class Invoice
{
    private:
        int numero;
        std::string descricao;
        int qtd; // quantidade do produto
        float preco;

    public:
        Invoice();

        void print();
        void setNumero(int num);
        void setDescricao(std::string desc);
        void setQtd(int qtd);
        void setPreco(float preco);

        int getNumero();
        std::string getDescricao();
        int getQtd();
        float getPreco();
        float getInvoiceAmount(); // quantidade * preco = montante
};

#endif // INVOICE_H
