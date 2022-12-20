/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package labsolid.jogoVelha1;

import java.util.Collection;

/**
 *
 * @author silva
 */
public class TabuleiroView {
    
    private String tabuleiroString(String[] spotsArray){
        String tabuleiroFormatado = "";
        for (int i = 0; i < spotsArray.length; i++){
            tabuleiroFormatado += spotsArray[i];
            if (i % 5 == 0){
                tabuleiroFormatado += "\n"; // todo spot multiplo de 5 quebra linha
            } else if (i != spotsArray.length-1){
                tabuleiroFormatado += " | "; // separa com pipeline com excecao do ultimo
            }
        }
        return tabuleiroFormatado;
    }
        
    public void display(Collection<String> spots) {
        String[] spotsArray = (String[]) spots.toArray();
        
        String tabuleiroFormatado = tabuleiroString(spotsArray);
        
        /** IMPLEMENTADO PENSANDO NO CASO ATUAL, E NÃO ABSTRAÇÃO (manutenabilidade de mudar o armazenamento do tabuleiro)
        //String tabuleiroFormatado = spots.get(0) + " | " + spots.get(1) + " | " + this.spots.get(2) + "\n" + this.spots.get(3) + " | " + this.spots.get(4) + " | " + this.spots.get(5) + "\n" + this.spots.get(6) + " | " + this.spots.get(7) + " | " + this.spots.get(8);
        */
        System.out.print(tabuleiroFormatado);
    }
    
}
