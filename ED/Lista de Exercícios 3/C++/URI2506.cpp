#include <iostream>

#define TAM_MAX 100

using namespace std;

template <class T>

class FilaSeq {
    private:
	    T dados[100];
	    int inicio;
	    int fim;
	    int nElementos;
	//private int tamMax;
	
    public:
        FilaSeq() {
            inicio = 0;
            fim = -1;
            nElementos = 0;
        }

		/** Verifica se a Fila está vazia */
		bool vazia () {
			if (nElementos == 0)
				return true;
			else
				return false;
		}

		/**Verifica se a Fila está cheia */
		bool cheia () {
			if (nElementos == TAM_MAX)
				return true;
			else
				return false;
		}

		/** Obtém o tamanho da Fila */
		int tamanho() {
			return nElementos;
		}

		/** Consulta o elemento do início da fila.
			Retorna -1 se a fila estiver vazia. */
		T primeiro() {
			if (vazia())
				return -1; // Erro: Fila vazia 
			
			return dados[inicio];
		}

		/**Insere um elemento no fim de uma fila
		Retorna false se a fila estiver cheia, true caso contrário. */
		bool insere(T valor) {
			if (cheia()){
				return false;
			}
		
			fim = (fim + 1) % TAM_MAX; // Circularidade 
			dados[fim] = valor;
			nElementos++;
			return true;
		}

		/**Remove o elemento do início da fila e retorna o valor removido.
			Retorna -1 se a fila estiver vazia.*/
		T remove() {
			if (vazia())
				return T();
		
			// Guarda o valor a ser removido
			//int valor = primeiro();
			T valor = dados[inicio];
			//cout << "Removendo " << valor.hora << " " << valor.minutos << " " << valor.tempoCritico << endl;
			
			// Atualiza o atributo inicio;
			inicio = (inicio + 1) % TAM_MAX; //Circularidade 
			nElementos--;
			return valor;
		}

		void mostrarFila(){
			for (int i = 0; i < nElementos; i++){
				//cout << "Paciente na fila " << dados[i].hora << " " << dados[i].minutos << " " << dados[i].tempoCritico << endl;
			}
		}
};

struct paciente{
    int hora;
    int minutos;
    int tempoCritico;
};

int diferencaTempo(int horas1, int minutos1, int horas2, int minutos2){
	int diferencaHoras = horas1 - horas2;
	int diferencaMinutos = minutos1 - minutos2;
	return (diferencaHoras * 60) + diferencaMinutos;
}

int main(void){
    int N, contCriticos, tempoHora, tempoMinutos;
    paciente atual, anterior;
    FilaSeq<paciente> pacientes;

    while (cin >> N){
		pacientes = FilaSeq<paciente>();
		contCriticos = 0;
		anterior = {0, 0, 0};
        for (int i = 0; i < N; i++){
            // atualizando o atual com a entrada (novo na fila)
            cin >> atual.hora;
            cin >> atual.minutos;
            cin >> atual.tempoCritico;

			if (i == 0){
				anterior = atual;
				continue;
			}
			
			//cout << "Atual agora " << atual.hora << " " << atual.minutos << " " << atual.tempoCritico << endl;
			//cout << "Anterior agora " << anterior.hora << " " << anterior.minutos << " " << anterior.tempoCritico << endl;

			int diferenca = diferencaTempo(atual.hora, atual.minutos, anterior.hora, anterior.minutos);
			//cout << "Diferenca de tempo " << diferenca << endl;

			if ((pacientes.vazia() && diferenca == 0) || !pacientes.vazia()){
				pacientes.insere(atual);
			}

			//cout << "Tamanho antes de remover " << pacientes.tamanho() << endl;
			
			int ticks = (int) (diferenca / 30);
			if (diferenca % 30 != 0){
				ticks++;
			}
			for (int j = 0; j < ticks; j++){
				paciente temp = pacientes.remove();
				//cout << "Paciente atendido: " << temp.hora << " " << temp.minutos << " " << temp.tempoCritico << endl;
			}

			// DEBUG
			pacientes.mostrarFila();
			//cout << "Tamanho " << pacientes.tamanho() << endl;
			int tempoEspera;
			//if (pacientes.vazia()){
			//	tempoEspera = 0;
			//} else {
				tempoEspera = pacientes.tamanho() * 30;
				if (0 < atual.minutos && atual.minutos < 30){
					//cout << "Sub de 30" << endl;
					tempoEspera += 30 - atual.minutos;
				} else if (30 < atual.minutos && atual.minutos <= 59){
					//cout << "Sub de 60" << endl;
					tempoEspera += 60 - atual.minutos;
				}
			//}

			//cout << "Tempo espera " << tempoEspera << endl;
            if (tempoEspera > atual.tempoCritico){
                contCriticos++;
            }
			anterior = atual;
			//cout << endl;
        }
		cout << contCriticos << endl;
    }

    return 0;
}