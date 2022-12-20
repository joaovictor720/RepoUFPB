#ifndef PILHA_SEQ
#define PILHA_SEQ

#define TAM_MAX 100

class PilhaSeq{
    private:
        unsigned long dados[TAM_MAX];
        int topo;
        unsigned long menor;

    public:
        PilhaSeq(){
            this->topo = -1;
            this->menor = -1;
        }
        //PilhaSeq(int n)
        virtual ~PilhaSeq(){}

        bool vazia(){
            if (this->topo == -1)
                return true;
            else 
                return false;
        }
        
        /**Verifica se a Pilha está cheia */
        bool cheia(){
            int size = sizeof(this->dados)/sizeof(this->dados[0]);
            if (this->topo == (size))
                return true;
            else
                return false;
        }
        
        /**Obtém o tamanho da Pilha*/
        int tamanho(){
            return this->topo+1;
        }
        
        /** Consulta o elemento do topo da Pilha.
            Retorna -1 se a pilha estiver vazia, 
            caso contrário retorna o valor que está no topo da pilha. */
        int top() {
            if (vazia()) 
                return -1; // pilha vazia
        
            return this->dados[this->topo];
        }
        
        /** Insere um elemento no topo da pilha.
            Retorna false se a pilha estiver cheia. 
            Caso contrário retorna true */
        bool push(int valor) {
            if (cheia()) 
                return false;  // err: pilha cheia
            if (valor < this->menor)
                this->menor = valor;
            this->topo++;
            this->dados[this->topo] = valor;
            return true;
        }   

        /** Retira o elemento do topo da pilha.
            Retorna -1 se a pilha estiver vazia. */
        int pop() {          
            if (vazia()) 
                return -1; // Pilha vazia

            int valor = this->dados[this->topo]; 
            if (valor == this->menor)

            this->topo--; 
            return valor;
        }
        
        unsigned long menorReduzindo(){
            unsigned long menorReduzindo = 999999999;
            unsigned long aux;
            while (tamanho() > 0){
                aux = this->pop();
                if (aux < menorReduzindo){
                    menorReduzindo = aux;
                }
            }
            return menorReduzindo;
        }
};

#endif