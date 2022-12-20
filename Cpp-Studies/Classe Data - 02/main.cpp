#include <iostream>
#include "Data.h"

using namespace std;

int main()
{
    Data d1;
    int dia, mes, ano;

    cin >> dia;
    cin >> mes;
    cin >> ano;

    d1.setDia(dia);
    d1.setMes(mes);
    d1.setAno(ano);

    d1.printData();

    return 0;
}
