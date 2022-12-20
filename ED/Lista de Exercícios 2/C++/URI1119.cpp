#include <iostream>

using namespace std;

class Node {

private:
	int conteudo;
	Node *ant;
	Node *prox;

public:
	Node();
	virtual ~Node();

	int getConteudo();
	Node *getProx();
	Node *getAnt();

	void setConteudo(int conteudo);
	void setProx(Node *prox);
	void setAnt(Node *ant);

};

#include <stdlib.h>

Node::Node() {
	setAnt(NULL);
	setProx(NULL);
}

Node::~Node() {
}

int Node::getConteudo() {
	return conteudo;
}

void Node::setConteudo(int conteudo) {
	this->conteudo = conteudo;
}

Node *Node::getProx() {
	return prox;
}

void Node::setProx(Node *prox) {
	this->prox = prox;
}

Node *Node::getAnt() {
	return ant;
}

void Node::setAnt(Node *ant) {
	this->ant = ant;
}

class LDE {

private:
	Node *inicio;
	Node *fim;
	int nElementos;

	bool insereInicioLista(int valor);
	bool insereMeioLista(int pos, int dado);
	bool insereFimLista(int dado);

	int removeInicioListaUnitaria();
	int removeInicioLista();
	int removeMeioLista(int pos);
	int removeFimLista();

public:
	LDE();
	LDE(int tamanho);
	LDE(float teste);
	virtual ~LDE();

	bool vazia();
	bool cheia();
	int tamanho();
	int elemento(int pos);
	int posicao (int valor);
	int posicao (int valor, int desloc);
	bool insere (int pos, int valor);
	int remove(int pos);
	void rotate(int clockRotation, int counterRotation);

};

#include <stdlib.h>
#include <iostream>

LDE::LDE() {
	inicio = NULL;
	fim = NULL;
	nElementos = 0;
}

LDE::LDE(float teste){
	
}

LDE::LDE(int tamanho){
	cout << "criando LDE" << endl;
	for (int i = 1; i <= tamanho; i++){
		this->insere(i, i);
	}
}

LDE::~LDE() {
}

/** Verifica se a Lista está vazia */
bool LDE::vazia() {
	if (nElementos == 0)
		return true;
	else
		 return false;
}

/**Obtém o tamanho da Lista*/
int LDE::tamanho() {
	return nElementos;
}

/** Obtém o i-ésimo elemento de uma lista
	Retorna o valor encontrado. */
int LDE::elemento (int pos) {
	Node *aux = inicio;
	int cont = 1;

	if (vazia())
		return -1; // Consulta falhou

	if ((pos < 1) || (pos > tamanho()))
		return -1; // Posicao invalida

	// Percorre a lista do 1o elemento até pos
	while (cont < pos){
		// modifica "aux" para apontar para o proximo elemento da lista
		aux = aux->getProx();
		cont++;
	}

	return aux->getConteudo();
}

/**Retorna a posição de um elemento pesquisado.
    Retorna 0 caso não seja encontrado */
int LDE::posicao (int dado) {
	int cont = 1;
	Node *aux;

	/* Lista vazia */
	if (vazia())
		return -1;

	/* Percorre a lista do inicio ao fim até encontrar o elemento*/
	aux = inicio;
	while (aux != NULL) {
		/* Se encontrar o elemento, retorna sua posicao n;*/
		if (aux->getConteudo() == dado)
			return cont;

		/* modifica "aux" para apontar para o proximo elemento da lista */
		aux = aux->getProx();
		cont++;
	}

	return -1;
}

	/** Insere nó em lista vazia */
bool LDE::insereInicioLista(int valor) {

	// Aloca memoria para novo no
	Node *novoNo = new Node();

	// Insere novo elemento na cabeca da lista
	novoNo->setConteudo(valor);
	novoNo->setProx(inicio);

	novoNo->setAnt(fim); // Nova instrucao
	if (vazia())
		fim = novoNo; // Nova instrucao
	else
		inicio->setAnt(novoNo); // Nova instrucao

	inicio = novoNo;
	nElementos++;
	return true;
}

/** Insere nó no meio da lista */
bool LDE::insereMeioLista(int pos, int dado){

	int cont = 1;

	// Aloca memoria para novo no
	Node *novoNo = new Node();
	novoNo->setConteudo(dado);

	// Localiza a pos. onde será inserido o novo nó
	Node *aux = inicio;
	while ((cont < pos-1) && (aux != NULL)){
		aux = aux->getProx();
		cont++;
	}

	if (aux == NULL)   // pos. inválida
		return false;

	// Insere novo elemento apos aux
	novoNo->setAnt(aux); // Nova instrucao
	novoNo->setProx(aux->getProx());

	aux->getProx()->setAnt(novoNo); // Nova instrucao

	aux->setProx(novoNo);

	nElementos++;
	return true;
}

/** Insere nó no fim da lista */
bool LDE::insereFimLista(int dado){
	// Aloca memoria para novo no
	Node *novoNo = new Node();
	novoNo->setConteudo(dado);
	novoNo->setProx(NULL);

	fim->setProx(novoNo);

	novoNo->setAnt(fim);  // Nova instrucao
	fim->setProx(novoNo); // Nova instrucao
	fim = novoNo; 		// Nova instrucao

	nElementos++;
	return true;
}

/**Insere um elemento em uma determinada posição
	Retorna true se conseguir inserir e false caso contrario */
bool LDE::insere(int pos, int dado) {

	if ((vazia()) && (pos != 1))
		return false; // lista vazia mas posicao inv

	// inserção no início da lista (ou lista vazia)
	if (pos == 1)
		return insereInicioLista(dado);
	/* inserção no fim da lista */
	else if (pos == nElementos+1)
		return insereFimLista(dado);
	/* inserção no meio da lista */
	else
		return insereMeioLista(pos, dado);
}

/** Remove elemento do início de uma lista unitária */
int LDE::removeInicioListaUnitaria(){
	int dado = inicio->getConteudo();

	delete inicio;

	inicio = NULL;
	fim = NULL;
	nElementos--;
	return dado;
}

/** Remove elemento do início da lista */
int LDE::removeInicioLista(){
	Node *p = inicio;

	// Dado recebe o dado removido
	int dado = p->getConteudo();

	// Retira o 1o elemento da lista (p)
	inicio = p->getProx();
	p->getProx()->setAnt(NULL);  // Nova instrucao

	nElementos--;

	// Libera a memoria da regiao apontada por p
	delete p;

	return dado;
}

/** Remove elemento no meio da lista */
int LDE::removeMeioLista(int pos){
	Node *p = inicio;
	int n = 1;

	// Localiza o nó que será removido
	while((n <= pos-1) && (p != NULL)){
		p = p->getProx();
		n++;
	}

	if (p == NULL)
		return -1; // pos. inválida

	int dado = p->getConteudo();
	p->getAnt()->setProx(p->getProx());
	p->getProx()->setAnt(p->getAnt());

	nElementos--;

	// Libera a memoria da regiao apontada por p
	delete p;

	return dado;
}

/** Remove elemento do início da lista */
int LDE::removeFimLista(){
	Node *p = fim;
	int dado = p->getConteudo();

	fim->getAnt()->setProx(NULL);
	fim = fim->getAnt();
	nElementos--;

	delete p;

	return dado;
}


/**Remove um elemento de uma determinada posição
	Retorna o valor a ser removido.
	-1 se a posição for inválida ou a lista estiver vazia*/
int LDE::remove(int pos) {
	// Lista vazia
	if (vazia())
		return -1;

	// Remoção do elemento da cabeça da lista
	if ((pos == 1) && (tamanho() == 1))
		return removeInicioListaUnitaria();
	else if (pos == 1)
		return removeInicioLista();
	// Remocao no fim da lista
	else if (pos == tamanho())
		return removeFimLista();
	// Remoção em outro lugar da lista
	else
		return removeMeioLista(pos);
}

void LDE::rotate(int clockRotation, int counterRotation){
	Node *clockwise = inicio;
	Node *counterclock = fim;
	//Node *clock1, *clock2; //salvadores do clockwise
	//Node *counter1, *counter2; //salvadores do counterclock
	
	// faz os oficiais andarem pela quantidade de vezes que tem de rinocerontes
	for (int k = 0; k < tamanho(); k++){
		cout << "indo ao segundo for" << endl;
		//clock1 = clockwise; //salva o ponteiro clockwise pra não ser apagado pelo garbage collector
		for (int i = 0; i < clockRotation; i++){
			if (clockwise->getConteudo() == 0){
				i--;
			}
			//clock2 = clock1; //salva o ponteiro clockwise pra não ser apagado pelo garbage collector
			clockwise = clockwise->getProx();
		}
		//counter1 = counterclock;
		for (int i = 0; i < counterRotation; i++){
			if (counterclock->getConteudo() == 0){
				i--;
			}
			//counter2 = counter1;
			counterclock = counterclock->getAnt();
		}
		
		//System.out.println("clockwise agora " + clockwise.getConteudo());
		//System.out.println("counterclock agora " + clockwise.getConteudo());

		std::cout << "clockwise agora " << clockwise->getConteudo();
		if (clockwise->getConteudo() == counterclock->getConteudo()){
			//System.out.print(" " + clockwise->getConteudo());
			std::cout << " " << clockwise->getConteudo();
		}else{
			//System.out.print("  " + clockwise->getConteudo() + "  " + counterclock->getConteudo());
			std::cout << "  " << counterclock->getConteudo() << "  " << counterclock->getConteudo();
		}
		
		clockwise->setConteudo(0);
		counterclock->setConteudo(0);
		
		if (k != tamanho()-1){
			//System.out.print(",");
			cout << ",";
		}   
	}
}

int main(void){
    int giroHorario, giroAntihorario, N;
    
    while(true){
        //N = input.nextInt();
        cin >> N;
        //giroHorario = input.nextInt();
        cin >> giroHorario;
        //giroAntihorario = input.nextInt();
        cin >> giroAntihorario;
		cout << "indo criar lista" << endl;
        LDE *lista = new LDE(N);
		cout << "lista criada, indo pro rotate" << endl;
        //int atualHorario = 1, atualAntihorario = 1;
        
        lista->rotate(giroHorario, giroAntihorario);
    }

    return 0;
}