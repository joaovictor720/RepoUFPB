package labsolid.apartamento3;

public class Studio extends Apartamento implements UpgradeApartamento {
    public Studio() {
        this.numeroQuartos = 0;
    }

    public void setAreaApartamento(int area) {
        this.areaApartamento = area;
    }
    
    public void upgrade() {
        this.areaApartamento += 40;
    }
}
