#ifndef DATA_H
#define DATA_H

#include <string>
#include <iostream>

class Data
{
    public:
        Data();
        int getDia();
        int getMes();
        std::string getMesString();
        int getAno();
        void setDia(int d);
        void setMes(int d);
        void setAno(int d);
        void printData();

        int mes;
    private:
        int dia;
        int ano;
};

#endif // DATA_H
