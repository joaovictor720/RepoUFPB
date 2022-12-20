/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package uri1031;

import java.util.Scanner;
import listas.*;

/**
 *
 * @author silva
 */
public class URI1031 {
    
    public static ListaCircular reduzirLista(ListaCircular lista, int pulo){
        int atual = 1;
        System.out.println("reduzindo lista com pulo " + pulo);
        // atual é o último removido
        while (lista.tamanho() > 1){
            System.out.println("tamanho da lista " + lista.tamanho());
            //System.out.println("removendo " + lista.remove(atual));
            int temp = lista.removePorConteudo(atual);
            System.out.println("removendo " + temp);
            atual = lista.andar(atual, pulo);
            System.out.println("andou para o " + atual);
        }
        return lista;
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner input = new Scanner(System.in);
        
        while(true){
            int nRegioes = input.nextInt();
            if (nRegioes == 0){
                break;
            }
            ListaCircular lista = new ListaCircular(nRegioes);
            ListaCircular listaAux = lista;
            int pulo = 0;
            
            while (true){
                pulo++;
                lista = reduzirLista(lista, 5);
                System.out.println("1 elemento = " + lista.elemento(1));
                if (lista.elemento(1) == 13){
                    System.out.println(pulo);
                    pulo = 0;
                    break;
                }
                System.out.println("renovando lista");
                lista = listaAux;
            }
        }
    }
}
