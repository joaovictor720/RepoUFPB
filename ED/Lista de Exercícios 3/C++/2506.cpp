#include <iostream>

using namespace std;

class Paciente{
    public:
        int hora;
        int minutos;
        int tempoCritico;

        int calculaTempoTotal(){
            int tempoTotal = 0;
            tempoTotal += hora*60;
            tempoTotal += minutos;
            return tempoTotal;
        }
};

int main(void){
    int N, contCriticos, relogio;
    Paciente atual, anterior;

    while (cin >> N){
		contCriticos = 0;
        relogio = 7*60;
        for (int i = 0; i < N; i++){
            // atualizando o atual com a entrada (novo na fila)
            cin >> atual.hora;
            cin >> atual.minutos;
            cin >> atual.tempoCritico;

            int tempoAtual = atual.calculaTempoTotal();
            while(relogio < tempoAtual){
                //cout << "relogio agora "<< relogio << endl;
                relogio += 30;
            }
            int tempoEspera = relogio - tempoAtual;
            //cout << "tempo espera " << tempoEspera << endl;
            if (tempoEspera > atual.tempoCritico){
                contCriticos++;
            }
            relogio += 30;
        }
		cout << contCriticos << endl;
    }

    return 0;
}