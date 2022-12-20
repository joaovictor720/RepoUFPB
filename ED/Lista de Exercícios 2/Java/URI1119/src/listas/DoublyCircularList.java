package listas;

public class DoublyCircularList {
	
	class Node {
		private Node prev;
		private int conteudo;
		private Node next;
		
		public Node(){
                        setData(0);
			setPrev(null);
			setNext(null);
		}

		public int getData() {
			return conteudo;
		}

		public void setData(int conteudo) {
			this.conteudo = conteudo;
		}

		public Node getNext() {
			return next;
		}

		public void setNext(Node prox) {
			this.next = prox;
		}

		public Node getPrev() {
			return prev;
		}

		public void setPrev(Node ant) {
			this.prev = ant;
		}
	}
	
	private Node start;
	private Node end;
	private int size;
	
	public DoublyCircularList(){
		start = null;
		end = null;		
		size = 0;
	}
        
        public DoublyCircularList(int tamanho){
            for (int i = 1; i <= tamanho; i++){
                this.insere(i, i);
            }
            System.out.println(start.getData());
            System.out.println(end.getData());
        }
	
	/** Verifica se a Lista está vazia */
	public boolean vazia() {
	    if (size == 0)
	        return true;
	    else
	        return false;
	}

	/**Obtém o tamanho da Lista*/
	public int size() {
	    return size;
	}

	/** Obtém o i-ésimo elemento de uma lista
	    Retorna o valor encontrado. */
	public int elemento (int pos) {
	    Node aux = start;
	    int cont = 1;

	    if (vazia()) {
	        return -1; // Consulta falhou 
	    }

	    if ((pos < 1) || (pos > size())){
	        return -1; // Posicao invalida 
	    }

	    // Percorre a lista do 1o elemento até pos 
	    while (cont < pos){
	        // modifica "aux" para apontar para o proximo elemento da lista 
	        aux = aux.getNext();
	        cont++;
	    }

	    return aux.getData();
	}

	/**Retorna a posição de um elemento pesquisado.
	    Retorna 0 caso não seja encontrado */
	public int posicao (int dado) {
	    int cont = 1;
	    Node aux;

	    /* Lista vazia */
	    if (vazia()) {
	        return -1;
	    }

	    /* Percorre a lista do inicio ao fim até encontrar o elemento*/
	    aux = start;
		while (aux != null) {
	        /* Se encontrar o elemento, retorna sua posicao n;*/
	        if (aux.getData() == dado){
	            return cont;
	        }

	        /* modifica "aux" para apontar para o proximo elemento da lista */
	        aux = aux.getNext();
	        cont++;
	    }

	    return -1;
	}

	/** Insere nó em lista vazia */
	private boolean insereInicioLista(int valor) {
		// Aloca memoria para novo no 
	    Node novoNo = new Node();
	    
	    // Insere novo elemento na cabeca da lista
	    novoNo.setData(valor);
	    novoNo.setNext(start);
	    
	    novoNo.setPrev(null); // Nova instrucao
	    if (vazia())
    			end = novoNo; // Nova instrucao
	    else
    			start.setPrev(novoNo); // Nova instrucao	    
	    
	    start = novoNo;
	    size++;
	    return true;
	}

	/** Insere nó no meio da lista */
	private boolean insereMeioLista(int pos, int dado){
	    int cont = 1;

	    // Aloca memoria para novo no
	    Node novoNo = new Node();
	    novoNo.setData(dado);

	    // Localiza a pos. onde será inserido o novo nó
	    Node aux = start;
	    while ((cont < pos-1) && (aux != null)){
	          aux = aux.getNext();
	          cont++;
	    }

	    if (aux == null) {  // pos. inválida 
	    		return false;
	    }

	    // Insere novo elemento apos aux
	    novoNo.setPrev(aux); // Nova instrucao
	    novoNo.setNext(aux.getNext());
	    
	    aux.getNext().setPrev(novoNo); // Nova instrucao
	    
	    aux.setNext(novoNo);

	    size++;
	    return true;
	}

	/** Insere nó no fim da lista */
	private boolean insereFimLista(int dado){
	    // Aloca memoria para novo no 
	    Node novoNo = new Node();
	    novoNo.setData(dado);

	    // Procura o final da lista 
	    Node aux = start;
	    while(aux.getNext() != null){
	        aux = aux.getNext();
	    }

	    novoNo.setNext(null);
	    aux.setNext(novoNo);
	    
	    novoNo.setPrev(end);  // Nova instrucao
	    end.setNext(novoNo); // Nova instrucao
	    end = novoNo; 		// Nova instrucao
	    
	    this.size++;
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
	    else if (pos == size+1){
	        return insereFimLista(dado);
	   }
	   /* inserção no meio da lista */
	   else{
	        return insereMeioLista(pos, dado);
	   }
	}

	// Remove elemento do início de uma lista unitária
	private int removeInicioListaUnitaria(){          
	    int dado = start.getData();
	    start = null;
	    end = null; 
	    size--;
	    return dado;
	}
	
	/** Remove elemento do início da lista */
	private int removeInicioLista(){
	    Node p = start;

	    // Dado recebe o dado removido
	    int dado = p.getData();

	    // Retira o 1o elemento da lista (p)
	    start = p.getNext();
	    p.getNext().setPrev(null);  // Nova instrucao
	    
	    size--;

	    // Sugere ao garbage collector que libere a memoria
	    //  da regiao apontada por p
	    p = null;

	    return dado;
	}

	/** Remove elemento no meio da lista */
	private int removeMeioLista(int pos){
	     Node p = start;
	     int n = 1;
	     
	     // Localiza o nó que será removido
	     while((n <= pos-1) && (p != null)){ 
	    	 	p = p.getNext();
	        n++;
	     }
	     
	     if (p == null) {
	    	 	return -1; // pos. inválida
	     }
	     
	    	 int dado = p.getData();
                 // vai no anterior do atual e faz ele apontar para o seguinte de atual
	    	 p.getPrev().setNext(p.getNext());
                 
                 // vai no seguinte do atual e faz ele apontar para o anterior do atual
	    	 p.getNext().setPrev(p.getPrev());
			 
	     size--;
	     
	     /* sugere ao garbage collector que libere a memoria
	     *  da regiao apontada por p*/
	    p = null;
	    return dado;
	}
	
	/** Remove elemento do início da lista */
	private int removeFimLista(){          
	     Node p = end;
	     int dado = p.getData();
	     
	     end.getPrev().setNext(null);
	     end = end.getPrev();
	     size--;
	     
	     p = null; 
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
	    if ((pos == 1) && (size() == 1)){ 
	 		 return removeInicioListaUnitaria();
	    }
	    else if (pos == 1){
	        return removeInicioLista();
	    }
	    // Remocao no fim da lista
	    else if (pos == size()){ 
	 		 return removeFimLista();
	    }
	    // Remoção em outro lugar da lista
	    else{
	        return removeMeioLista(pos);
	    }
	}	
        
        public int girarHorario(int atual, int giro){
            Node aux = new Node();
            while (aux.getData() != atual){
                aux = aux.getNext();
            }
            for (int i = 0; i < giro; i++){
                aux = aux.getNext();
            }
            int dado = aux.getData();
            aux.setData(0);
            
            return dado;
        }
        
        public int girarAntihorario(int atual, int giro){
            Node aux = new Node();
            while (aux.getData() != atual){
                aux = aux.getPrev();
            }
            for (int i = 0; i < giro; i++){
                aux = aux.getPrev();
            }
            int dado = aux.getData();
            aux.setData(0);
            
            return dado;
        }
        
        /*
        Eu crio dois ponteiros: horario, antihorario.
        o horario inicia com a base (eu sei, contráditório, mas funciona) e o antihorario com a cabeça. 
        Vou considerar o exemplo N = 10, k = 4 e m = 3.

        eu faço horario = horario.getProx() 4x e faço antihorario = antihorario.getAnt() 3x; 
        Imprimo os dois se eles forem diferentes ou imprimo apenas um e ent marco com 0.

        Na proxima execução horario estará apontando para 4 e antihorario para 8; Repito novamente:

        faço horario = horario.getProx() 4x. 

        O cuidado vem aqui:  antihorario = antihorario.getAnt() 3x, mas em cada uma dessas vezes eu 
        verifico se eu já tinha passado por lá, caso sim, eu ando até chegar em um número q eu n tenha
        passado ainda mas isso sem contar nas 3x; Imprimo os dois se eles forem diferentes ou imprimo 
        apenas um e ent marco com 0.
        */
        
        public void rotate(int clockRotation, int counterRotation){
            Node clockwise = end;
            Node counterclock = start;
            Node clock1, clock2; //salvadores do clockwise
            Node counter1, counter2; //salvadores do counterclock
            
            System.out.println(start.getData());
            System.out.println(end.getData());
            
            // faz os oficiais andarem pela quantidade de vezes que tem de rinocerontes
            while (true){
                if (size() == 1){
                    System.out.println("  " + elemento(1));
                    remove(1);
                    return;
                }
                clock1 = clockwise; //salva o ponteiro clockwise pra não ser apagado pelo garbage collector
                for (int i = 0; i < clockRotation; i++){
                    
                    /*if (clock1.getData() == 0){
                        i--;
                    }*/
                    clock2 = clock1; //salva o ponteiro clockwise pra não ser apagado pelo garbage collector
                    clock2 = clock2.getNext();
                }
                counter1 = counterclock;
                for (int i = 0; i < counterRotation; i++){
                    /*if (counter1.getData() == 0){
                        i--;
                    }*/
                    counter2 = counter1;
                    counter2 = counter2.getPrev();
                }
                
                /*
                System.out.println("clockwise agora " + clockwise.getData());
                System.out.println("counterclock agora " + clockwise.getData());
                if (clockwise.getData() == counterclock.getData()){
                    System.out.print(" " + clockwise.getData());
                }else{
                    System.out.print("  " + counterclock.getData() + "  " + counterclock.getData());
                }
                
                
                clockwise.setData(0);
                counterclock.setData(0);
                */
                
                if(clockwise == counterclock) {
                    int pos = getPos(clockwise.getData());
                    //cout << " " << horario->getValue() << ", ";
                    System.out.println(" " + clockwise.getData() + ", ");
                    clockwise = clockwise.getPrev();
                    counterclock = counterclock.getNext();
                    remove(pos);
                    continue;
                }

                int posHorario = getPos(clockwise.getData());
                //cout << "  " << horario->getValue();
                System.out.println("  " + clockwise.getData());
                clockwise = clockwise.getPrev();
                remove(posHorario);

                int posAnti = getPos(counterclock.getData());
                //cout << "  " << antihorario->getValue() << ", ";
                System.out.println("  " + clockwise.getData());
                counterclock = counterclock.getPrev();
                remove(posAnti);
                
                /*
                if (k != size()){
                    System.out.print(",");
                }*/   
            }
            //System.out.println();
        }
        
        public int getPos(int value) {
            if(vazia()) {
                return -1;
            }

            Node auxNode = start;

            for(int i = 1; i <= size(); i++) {
                if(auxNode.getData() == value) {
                    return i;
                }

                auxNode = auxNode.getNext();
            }

            return -1;
        }

}