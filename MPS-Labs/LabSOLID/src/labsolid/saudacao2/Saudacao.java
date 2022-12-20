public class Saudacao {
    private Formalidade formalidade;

    public Saudacao(Formalidade formalidade) {
        this.formalidade = formalidade;
    }

    public String getSaudarFromFormalidade() {
        return this.formalidade.saudar();
    }
}
