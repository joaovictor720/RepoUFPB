/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package uri1068;

import java.util.NoSuchElementException;
import java.util.Scanner;
import pilhas.PilhaSeq;

/**
 *
 * @author silva
 */
public class URI1068 {
    
    public static void mostrarPilha(PilhaSeq pilha){
        if (pilha.vazia()){
            System.out.println("pilha vazia");
            return;
        }else{
            System.out.println("pilha com elementos:");
        }
        for (int i = 0; i < pilha.tamanho(); i++){
            System.out.println("elemento " + (char) pilha.pop());
        }
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner input = new Scanner(System.in);
        String expressao;
        int N = 10000;
        
        while (N-- > 0){
            PilhaSeq pilha = new PilhaSeq(1000);
            try {
                expressao = input.nextLine();
            } catch (NoSuchElementException exc){
                continue;
            }
            boolean fechouSemAbrir = false;
            
            for (int i = 0; i < expressao.length(); i++){
                if (expressao.charAt(i) == '('){
                    pilha.push('(');
                }
                if (expressao.charAt(i) == ')'){
                    if (pilha.vazia()){
                        fechouSemAbrir = true;
                        break;
                    }else{
                        pilha.pop();
                    }
                }
            }
            if (pilha.vazia() && !fechouSemAbrir){
                System.out.println("correct");
            }else{
                System.out.println("incorrect");
            }
        }
    }
    
}
