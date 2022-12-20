#ifndef INVOICE_H
#define INVOICE_H

#include <string>

class Invoice
{
    public:
        int numero;
        std::string descricao;
        int qtd;
        float preco;

        Invoice();
        float getInvoiceAmount();
};

#endif // INVOICE_H
