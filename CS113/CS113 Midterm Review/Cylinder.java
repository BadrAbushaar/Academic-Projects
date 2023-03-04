public class Cylinder extends Circle {
    private double height;

    public Cylinder(double height, double radius) {
        this.height = height;
        super(r);
    }

    public double getHeight() {
        return this.height;
    }

    public void setHeight(double height) {
        this.height = height;
    }

    public boolean equals(Cylinder other) {
        if (this.getRadius() == other.getRadius() && this.getHeight() == other.getHeight()) {
            return true;
        } else {
            return false;
        }
    }

    @Override
    public double area() {
        return Math.PI * radius * radius * height;
    }

    @Override
    public String toString
    {
        return "Cylinder Radius: " + radius + "/nCylinder Height: " + height;
    }
}
