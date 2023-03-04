public class EV {
    private int range;
    private String model;

    public EV(int range, String model) {
        this.range = range;
        this.model = model;
    }

    public int getRange() { return range; }
    public String getModel() {return model; }

    public void setRange(int range) { this.range = range; }
    public void setModel(String model) { this.model = model; }

    public String toString() { return "Model: " + model + "\nRange: " + range; }

    public int compareTo(EV otherEV) {
        if (this.range > otherEV.getRange()) {
            return 1;
        } else if (this.range < otherEV.getRange()) {
            return -1;
        } else {
            return 0;
        }
    }

    public boolean sameModel(EV otherEV) {
        return this.model.equals(otherEV.getModel());
    }
}
