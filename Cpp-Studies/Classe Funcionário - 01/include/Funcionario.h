#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>

class Funcionario
{
    public:
        std::string nome;
        std::string sobrenome;
        float salario;

        Funcionario();
        int getSalarioAnual();

    protected:

    private:
};

#endif // FUNCIONARIO_H
