public class MonetaryCoin extends Coin{
    private int centValue;

    public void setCentValue(int newCentValue) {
        this.centValue = newCentValue;
    }

    public int getCentValue() {
        return centValue;
    }

    @Override
    public String toString() {
        return super.toString() + " " + centValue;
    }
}