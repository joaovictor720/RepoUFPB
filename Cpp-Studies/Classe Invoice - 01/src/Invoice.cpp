#include "Invoice.h"

Invoice::Invoice()
{
    numero = 0;
    qtd = 0;
    preco = 0;
}

float Invoice::getInvoiceAmount(){
    return qtd * preco;
}
