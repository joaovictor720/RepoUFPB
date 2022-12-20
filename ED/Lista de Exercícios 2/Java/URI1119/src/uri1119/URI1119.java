/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package uri1119;

import java.util.Scanner;
import listas.DoublyCircularList;

/**
 *
 * @author João Victor
 */
public class URI1119 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner input = new Scanner(System.in);
        int giroHorario, giroAntihorario, N;
        
        while(true){
            N = input.nextInt();
            giroHorario = input.nextInt();
            giroAntihorario = input.nextInt();
            DoublyCircularList lista = new DoublyCircularList(N);
            
            lista.rotate(giroHorario, giroAntihorario);
        }
        
    }
    
}
