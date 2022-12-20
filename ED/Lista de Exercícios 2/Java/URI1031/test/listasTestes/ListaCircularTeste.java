/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package listasTestes;

import listas.ListaCircular;

/**
 *
 * @author silva
 */
public class ListaCircularTeste {
    
    public static void main(String[] args){
        ListaCircular lista = new ListaCircular(4);
        
        for (int i = 1; i <= lista.tamanho(); i++)
            System.out.println(lista.elemento(lista.tamanho() + i));
        
        // print do ultimo
        System.out.println(lista.elemento(lista.tamanho()));
        
        // print muito longe
        System.out.println("print alem do tamanho " + lista.remove(4));
        System.out.println("print alem do tamanho " + lista.elemento(4));
    }
}
