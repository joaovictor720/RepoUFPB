#include <iostream>

using namespace std;

class No
{
private:
    No *ant;
    int conteudo;
    No *prox;

public:
    No();
    ~No();

    No *getAnt();
    int getConteudo();
    No *getProx();

    void setAnt(No *ant);
    void setConteudo(int conteudo);
    void setProx(No *prox);
};

No::No(/* args */)
{
    setAnt(NULL);
	setProx(NULL);
}

No::~No()
{
}

No *No::getAnt(){
    return ant;
}
int No::getConteudo(){
    return conteudo;
}
No *No::getProx(){
    return prox;
}

void No::setAnt(No *ant){
    this->ant = ant;
}
void No::setConteudo(int conteudo){
    this->conteudo = conteudo;
}
void No::setProx(No *prox){
    this->prox = prox;
}


class Lista
{
private:
    No *inicio;
	No *fim;
    int nElementos;

    bool insereInicioLista(int valor);
	bool insereMeioLista(int pos, int dado);
	bool insereFimLista(int dado);

	int removeInicioListaUnitaria();
	int removeInicioLista();
	int removeMeioLista(int pos);
	int removeFimLista();

public:
    Lista(/* args */);
    ~Lista();

    No *getInicio();
    No *getFim();
    int getNelementos();

    void setInicio(No *inicio);
    void setFim(No *fim);
    void setNelementos(int nElementos);

    bool vazia();
	bool cheia();
	int tamanho();
	int elemento(int pos);
	int posicao (int valor);
	int posicao (int valor, int desloc);
	bool insere (int pos, int valor);
	int remove(int pos);
    int alteraConteudo(int pos, int valor);


};

Lista::Lista(/* args */)
{
    inicio = NULL;
    fim = NULL;
    nElementos = 0;
}

Lista::~Lista()
{
}

No *Lista::getInicio(){
    return inicio;
}
No *Lista::getFim(){
    return fim;
}
int Lista::getNelementos(){
    return nElementos;
}

void Lista::setInicio(No *inicio){
    this->inicio = inicio;
}
void Lista::setFim(No *fim){
    this->fim = fim;
}
void Lista::setNelementos(int nElementos){
    this->nElementos = nElementos;
}

/** Verifica se a Lista está vazia */
bool Lista::vazia() {
	if (nElementos == 0)
		return true;
	else
		 return false;
}

/*Obtém o tamanho da Lista*/
int Lista::tamanho() {
	return nElementos;
}

/** Obtém o i-ésimo elemento de uma lista
	Retorna o valor encontrado. */
int Lista::elemento (int pos) {
	No *aux = inicio;
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
int Lista::posicao (int dado) {
	int cont = 1;
	No *aux;

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
bool Lista::insereInicioLista(int valor) {

	// Aloca memoria para novo no
	No *novoNo = new No();

	// Insere novo elemento na cabeca da lista
	novoNo->setConteudo(valor);
	novoNo->setProx(inicio);

	novoNo->setAnt(NULL); // Nova instrucao
	if (vazia())
		fim = novoNo; // Nova instrucao
	else
		inicio->setAnt(novoNo); // Nova instrucao

	inicio = novoNo;
	nElementos++;
	return true;
}

/** Insere nó no meio da lista */
bool Lista::insereMeioLista(int pos, int dado){

	int cont = 1;

	// Aloca memoria para novo no
	No *novoNo = new No();
	novoNo->setConteudo(dado);

	// Localiza a pos. onde será inserido o novo nó
	No *aux = inicio;
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
bool Lista::insereFimLista(int dado){
	// Aloca memoria para novo no
	No *novoNo = new No();
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
bool Lista::insere(int pos, int dado) {

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
int Lista::removeInicioListaUnitaria(){
	int dado = inicio->getConteudo();

	delete inicio;

	inicio = NULL;
	fim = NULL;
	nElementos--;
	return dado;
}

/** Remove elemento do início da lista */
int Lista::removeInicioLista(){
	No *p = inicio;

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
int Lista::removeMeioLista(int pos){
	No *p = inicio;
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
int Lista::removeFimLista(){
	No *p = fim;
	int dado = p->getConteudo();

	fim->getAnt()->setProx(NULL);
	fim = fim->getAnt();
	nElementos--;

	delete p;

	return dado;
}

int Lista::alteraConteudo(int pos, int dado){
    No *aux = inicio;
	int cont = 1;

	if (vazia())
		return -1; 

	if ((pos < 1) || (pos > tamanho()))
		return -1; 

	
	while (cont < pos){
		aux = aux->getProx();
		cont++;
	}

	aux->setConteudo(dado);

    return aux->getConteudo();
}


/**Remove um elemento de uma determinada posição
	Retorna o valor a ser removido.
	-1 se a posição for inválida ou a lista estiver vazia*/
int Lista::remove(int pos) {
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
int main(void){
    int n, k, m, aux, contador, escInicio, escFim, primeira, segunda;

    while (1)
    {
        cin >> n >> k >> m;

        Lista *minhaLista = new Lista();
		
        if (n == 0 && m == 0 && k == 0)break;

        escFim = n - 1;
        escInicio = 0;

        for(int i = 0; i < n; i++)
            minhaLista->insere(i+1, i+1);

        //for(int i = 0; i < n; i++)
            //cout << minhaLista.elemento(i+1) << endl;

        contador = 0;
        while(contador < minhaLista->tamanho()) {
            aux = k;
            while (aux > 0){
                if(minhaLista->elemento(escInicio+1) > 0) aux--;
                if(aux == 0) primeira = escInicio+1;
                escInicio = (escInicio + 1) % n;
                //cout << escInicio << endl;
            }

            aux = m;
            while (aux > 0){
                if(minhaLista->elemento(escFim+1) > 0) aux--;
                if(aux == 0) segunda = escFim+1;
                escFim = (escFim + n - 1) % n;
            }

            if(contador > 0)
                cout <<",";

            if(primeira != segunda) {
                printf("%3d%3d", minhaLista->elemento(primeira), minhaLista->elemento(segunda));
                contador += 2;
            } else {
                printf("%3d", minhaLista->elemento(primeira));
                contador++;
            }
            minhaLista->alteraConteudo(primeira, 0);
            minhaLista->alteraConteudo(segunda, 0);


        }
        cout << endl;
        delete minhaLista;

    }

    


    return 0;
}