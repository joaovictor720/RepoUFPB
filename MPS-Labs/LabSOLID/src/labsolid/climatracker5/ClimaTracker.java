package labsolid.climatracker5;

public class ClimaTracker {

    String condicaoAtual;
    GeradorAlerta gerador;

    public ClimaTracker() {
        this.gerador = new Phone();
    }

    public void setCondicaoAtual(String condicaoClimatica) {
        this.condicaoAtual = condicaoClimatica;
        if (this.condicaoAtual == "chovendo") {
            this.gerador = new Phone();
        }
        if (this.condicaoAtual == "ensolarado") {
            this.gerador = new EmailCliente();
        }
    }

    /**
     * SRP (Responsabilidade Única) violado antes: método de alerta separado do
     * método de settar a condição atual
     *
     * DIP (Inversão de Dependência) violado: Criada a interface 'GeradorAlerta'
     * para abstrair as mensagens de alerta de cada dispositivo
     */
    public void alertar() {
        String alerta = gerador.geraClimaAlerta(this.condicaoAtual);
        System.out.print(alerta);
    }
}
