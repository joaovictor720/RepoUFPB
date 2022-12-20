package pilhas;

public class PilhaSeq implements Cloneable {
    private int dados[]; // Vetor que contém os dados da lista 
    private int topo; 
    
    @Override
    public Object clone() throws CloneNotSupportedException
    {
        return super.clone();
    }

    public PilhaSeq(){
    	dados = new int[100];
    	topo = -1;
    }
    
    public PilhaSeq(int n){
    	dados = new int[n];
    	topo = -1;
    }

    /** Verifica se a Pilha está vazia */
    public boolean vazia(){
    	if (topo == -1)
            return true;
    	else 
    	    return false;
    }
	
    /**Verifica se a Pilha está cheia */
    public boolean cheia(){
        if (topo == (dados.length-1))
            return true;
        else
            return false;
    }
	
    /**Obtém o tamanho da Pilha*/
    public int tamanho(){
	return topo+1;
    }
    
    /** Consulta o elemento do topo da Pilha.
        Retorna -1 se a pilha estiver vazia, 
        caso contrário retorna o valor que está no topo da pilha. */
    public int top() {
        if (vazia()) 
            return -1; // pilha vazia
 	  
        return dados[topo];
    }
     
    /** Insere um elemento no topo da pilha.
        Retorna false se a pilha estiver cheia. 
        Caso contrário retorna true */
    public boolean push(int valor) {
        if (cheia()) 
            return false;  // err: pilha cheia
        topo++;
        dados[topo] = valor;
        return true;
    }   

    /** Retira o elemento do topo da pilha.
        Retorna -1 se a pilha estiver vazia. */
    public int pop() {          
        if (vazia()) 
            return -1; // Pilha vazia

        int valor = dados[topo]; 
        topo--; 
        return valor;
    }
    
    public int menor(){
        int menor = 999999999;
        int aux;
        while (tamanho() > 0){
            aux = this.pop();
            if (aux < menor){
                menor = aux;
            }
        }
        return menor;
    }
}
