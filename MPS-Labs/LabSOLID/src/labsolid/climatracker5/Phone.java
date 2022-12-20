package labsolid.climatracker5;

public class Phone implements GeradorAlerta {
    public String geraClimaAlerta(String condicaoClimatica) {
        String alerta = "Estah " + condicaoClimatica;
        return alerta;
    }
}
