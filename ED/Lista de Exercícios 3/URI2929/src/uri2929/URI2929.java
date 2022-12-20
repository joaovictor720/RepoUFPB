/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package uri2929;

import java.util.Scanner;
import pilhas.PilhaSeq;
import java.io.*;

/**
 *
 * @author silva
 */
public class URI2929 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws CloneNotSupportedException, IOException {
        // TODO code application logic here
        Scanner input = new Scanner(System.in);
        //BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        PilhaSeq pilha = new PilhaSeq();
        PilhaSeq pilhaAux = (PilhaSeq) pilha.clone();
        
        //System.out.println("esperando nOp");
        //int nOp = input.nextInt();
        //System.out.println("esperando cin.ignore");
        //input.next();
        //input.next();
        String operacao;
        int operando;
        
        for (int i = 0; i < 11; i++){
            System.out.println("esperando operacao");
            operacao = input.nextLine();
            //String comando[] = new String[2];
            //comando = operacao.split(" ");
            System.out.println("esperando operando");
            operando = input.nextInt();
            
            System.out.println("operacao " + operacao);
            System.out.println("operando " + operando);
            
            switch (operacao) {
                case "PUSH":
                    //Integer presente = Integer.parseInt(operando);
                    pilha.push(operando);
                    break;
                case "POP":
                    pilha.pop();
                    break;
                case "MIN":
                    int menor = pilhaAux.menor();
                    System.out.println(menor);
                    break;
                default:
                    System.out.println("Entrada invalida");
            }
        }
    }
    
}
