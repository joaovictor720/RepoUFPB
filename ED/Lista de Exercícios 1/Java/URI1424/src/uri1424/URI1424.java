/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package uri1424;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

/**
 *
 * @author silva
 */
public class URI1424 {
    
    /**
     * @param dict HashMap com os valores do vetor principal e suas posições de ocorrência
     * @param nElementos
     * @param input
     */ 
    public static void preencherDict(HashMap<Integer, ArrayList<Integer>> dict, int nElementos, Scanner input){
        for (int i = 0; i < nElementos; i++){
            int temp = input.nextInt();
            if (dict.get(temp) == null){
                ArrayList<Integer> posicoes = new ArrayList<>(0);
                dict.put(temp, posicoes);
            }
            dict.get(temp).add(i+1);
        }
    }

    public static int consultar(HashMap<Integer, ArrayList<Integer>> dict, int nOcorrencia, int busca){
        try {
            if (dict.get(busca).get(nOcorrencia-1) != null){
                return dict.get(busca).get(nOcorrencia-1);
            }else{
                return -1;
            }
        }catch (Exception exc){
            return -1;
        }
    }
    
    /**
     * @param args
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner input = new Scanner(System.in);
        int nElementos, nConsultas, nOcorrencia, busca;
        HashMap<Integer, ArrayList<Integer>> hash = new HashMap<>();
        
        while(input.hasNext()){
            nElementos = input.nextInt();
            nConsultas = input.nextInt();
            
            preencherDict(hash, nElementos, input);
            
            for (int i = 0; i < nConsultas; i++){
                nOcorrencia = input.nextInt();
                busca = input.nextInt();
                int consulta = consultar(hash, nOcorrencia, busca);
                
                if (consulta != -1){
                    System.out.println(consulta);
                }else{
                    System.out.println(0);
                }
            }
            hash.clear();
        }
    }
    
}
