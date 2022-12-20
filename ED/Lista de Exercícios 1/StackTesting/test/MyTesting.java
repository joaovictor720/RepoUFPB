/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
import pilhas.PilhaSeq;
import java.util.Stack;

/**
 *
 * @author silva
 */
public class MyTesting {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        PilhaSeq myStack = new PilhaSeq(10);
        //Stack<Integer> javaStack = new Stack<>();
        
        System.out.println(myStack.vazia());
        System.out.println(myStack.tamanho());
        //System.out.println(javaStack.empty());
        
        myStack.push(42);
        myStack.push(10);
        myStack.push(69);
        
        System.out.println(myStack.top());
        System.out.println(myStack.vazia());
        
        int popped = myStack.pop();
        System.out.println(popped);
        System.out.println(myStack.top());
    }
    
}
