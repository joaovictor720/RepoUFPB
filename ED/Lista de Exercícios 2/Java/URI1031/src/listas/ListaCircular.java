package listas;

public class ListaCircular {
	
	private No cabeca;
	private int tamanho;
	
	public ListaCircular(){
		cabeca = null;
		tamanho = 0;
	}
        
        public ListaCircular(int tamanho){
            
            // Constrói enumerando de 1 a tamanho
            for (int i = 1; i <= tamanho; i++){
                this.insere(i, i);
                System.out.println("NOVO NO ALOCADO " + i);
            }
        }
	
	/** Verifica se a Lista está vazia */
	public boolean vazia() {
	    if (tamanho == 0)
	        return true;
	    else
	        return false;
	}

	/**Obtém o tamanho da Lista*/
	public int tamanho() {
	    return tamanho;
	}

	/** Obtém o i-ésimo elemento de uma lista
	    Retorna o valor encontrado. */
	public int elemento (int pos) {
	    No aux = cabeca;
	    int cont = 1;

	    if (vazia() || (pos < 1)) {
	        return -1; // Consulta falhou 
	    }
            /*
	    if ((pos < 1) || (pos > tamanho())){
	        return -1; // Posicao invalida 
	    }*/

	    // Percorre a lista do 1o elemento até pos 
	    while (cont < pos){
	        // modifica "aux" para apontar para o proximo elemento da lista 
	        aux = aux.getProx();
	        cont++;
	    }

	    return aux.getConteudo();
	}

	/**Retorna a posição de um elemento pesquisado.
	    Retorna 0 caso não seja encontrado */
	public int posicao (int dado) {
	    int cont = 1;
	    No aux;

	    /* Lista vazia */
	    if (vazia()) {
	        return -1;
	    }

	    /* Percorre a lista do inicio ao fim até encontrar o elemento*/
	    aux = cabeca;
		while (aux != null) {
	        /* Se encontrar o elemento, retorna sua posicao n;*/
	        if (aux.getConteudo() == dado){
	            return cont;
	        }

	        /* modifica "aux" para apontar para o proximo elemento da lista */
	        aux = aux.getProx();
	        cont++;
	    }

	    return -1;
	}

	/** Insere nó em lista vazia */
	private boolean insereInicioLista(int valor) {
	    // Aloca memoria para novo no 
	    No novoNo = new No();
	    
	    // Insere novo elemento na cabeca da lista
	    novoNo.setConteudo(valor);
	    novoNo.setProx(cabeca);
	    cabeca = novoNo;
	    tamanho++;
	    return true;
	}

	/** Insere nó no meio da lista */
	private boolean insereMeioLista(int pos, int dado){
	    int cont = 1;

	    // Aloca memoria para novo no
	    No novoNo = new No();
	    novoNo.setConteudo(dado);

	    // Localiza a pos. onde será inserido o novo nó
	    No aux = cabeca;
	    while ((cont < pos-1) && (aux != null)){
	          aux = aux.getProx();
	          cont++;
	    }

	    if (aux == null) {  // pos. inválida 
	    		return false;
	    }

	    // Insere novo elemento apos aux
	    novoNo.setProx(aux.getProx());
	    aux.setProx(novoNo);

	    tamanho++;
	    return true;
	}

	/** Insere nó no fim da lista */
	private boolean insereFimLista(int dado){
	    // Aloca memoria para novo no 
	    No novoNo = new No();
	    novoNo.setConteudo(dado);

	    // Procura o final da lista 
	    No aux = this.cabeca;
            int cont = 0;
	    while(++cont < tamanho()){
	        aux = aux.getProx();
	    }

	    novoNo.setProx(cabeca);
	    aux.setProx(novoNo);

	    this.tamanho++;
	    return true;
	}

	/**Insere um elemento em uma determinada posição
	    Retorna true se conseguir inserir e 
	    false caso contrario */
	public boolean insere(int pos, int dado) {
		if ((vazia()) && (pos != 1)){
	        return false; /* lista vazia mas posicao inv*/
	    }

	 	/* inserção no início da lista (ou lista vazia)*/
	    if (pos == 1){
	        return insereInicioLista(dado);
	    }
	    /* inserção no fim da lista */
	    else if (pos == tamanho+1){
	        return insereFimLista(dado);
	   }
	   /* inserção no meio da lista */
	   else{
	        return insereMeioLista(pos, dado);
	   }
	}

	/** Remove elemento do início da lista */
	private int removeInicioLista(){
            System.out.println("removendo no inicio");
	    No p = cabeca;

	    // Dado recebe o dado removido
	    int dado = p.getConteudo();

	    // Retira o 1o elemento da lista (p)
	    cabeca = p.getProx();
	    tamanho--;

	    // Sugere ao garbage collector que libere a memoria
	    //  da regiao apontada por p
	    p = null;

	    return dado;
	}

	/** Remove elemento no meio da lista */
	private int removeNaLista(int pos){
            System.out.println("removendo na lista, pos " + pos);
	     No atual = null, antecessor = null;
	     int dado = -1;
	     int cont = 1;

	     /* Localiza o nó que será removido*/
	     atual = cabeca;
	     while((cont < pos) && (atual != null)){
	           antecessor = atual;
	           atual = atual.getProx();
	           cont++;
	     }

	     if (atual == null) { /* pos. inválida */
	        return -1;
	     }

	    /* retira o elemento da lista */
	    dado = atual.getConteudo();
	    antecessor.setProx(atual.getProx());
	    tamanho--;

	    /* sugere ao garbage collector que libere a memoria
	     *  da regiao apontada por p*/
	    atual = null;
	    return dado;
	}

	/**Remove um elemento de uma determinada posição
	    Retorna o valor a ser removido. 
	    -1 se a posição for inválida ou a lista estiver vazia*/
	public int remove(int pos) {
		// Lista vazia 
	    if (vazia()) {
	    		return -1;
	    }

	    // Remoção do elemento da cabeça da lista 
	    if (pos == 1){
	        return removeInicioLista();
	    }
	    // Remoção em outro lugar da lista
	    else{
	        return removeNaLista(pos);
	    }
	}
        
        // DEBUG
        public void mostrarLista(){
            for (int i = 0; i < tamanho; i++){
                System.out.println(elemento(i));
            }
        }
        
        // método meio redundante
        public int removePorConteudo(int valor){
            No atual = cabeca, antecessor = null;
            int cont = tamanho();
            while (cont-- > 0){
                antecessor = atual;
                atual = atual.getProx();
                if (atual.getConteudo() == valor){
                    antecessor.setProx(atual.getProx());
                    return valor;
                }
            }
            tamanho--;
            mostrarLista();
            return valor;
        }
        
        public int andar(int atual, int pulo){
            No aux = cabeca;
            //int numDePassos = atual+pulo;
            
            while(aux.getConteudo() == atual){
                System.out.println("andou para " + aux.getConteudo());
                aux = aux.getProx();
                //System.out.println("conteudo de aux " + aux.getConteudo());
            }
            
            while(pulo-- > 0){
                System.out.println("andou para " + aux.getConteudo());
                aux = aux.getProx();
                //System.out.println("conteudo de aux " + aux.getConteudo());
            }
            System.out.println("andou para " + aux.getConteudo());
            return aux.getConteudo();
        }
        
        public No pular(No atual, int pulo){
            No aux = atual;
            while(pulo-- != 0){
                aux = aux.getProx();
            }
            return aux;
        }
}


