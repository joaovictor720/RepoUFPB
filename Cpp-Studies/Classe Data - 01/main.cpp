#include <iostream>
#include "Data.h"

using namespace std;

int main(){
    Data d1;

    cout << d1.dia << '/' << d1.mes << '/' << d1.ano << endl;
    cin >> d1.dia;
    cin >> d1.mes;
    cin >> d1.ano;
    cout << d1.dia << '/' << d1.mes << '/' << d1.ano << endl;

    return 0;
}
