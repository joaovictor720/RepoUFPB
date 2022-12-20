package labsolid.apartamento3;

public class Cobertura extends Apartamento implements UpgradeApartamento {
    public Cobertura() {
        this.numeroQuartos = 4;
    }

    public void setAreaApartamento(int area) {
        this.areaApartamento = area;
    }
    
    public void upgrade() {
        this.areaApartamento += 40;
        this.numeroQuartos += 1;
    }
}
