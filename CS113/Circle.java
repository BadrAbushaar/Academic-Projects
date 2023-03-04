public class Circle {
    private Point center;
    private int radius;

    // Constructor
    public Circle(Point circleCenter, int circleRadius) {
        center = circleCenter;
        radius = circleRadius;
    }

    // Getter for each instance data
    public Point getCenter() { return center; }
    public int getRadius() { return radius; }

    // Setter for each instance data
    public void setCenter(Point newCenter) { center = newCenter; }
    public void setRadius(int newRadius) { radius = newRadius; }

    // Equals method
    public boolean equals(Circle otherCircle) {
        if (radius == otherCircle.getRadius()) {
            return true;
        } else {
            return false;
        }
    }

    // Area method
    public double area() {
        return Math.PI * radius * radius;
    }

    // toString method
    public String toString() {
        return "Center: " + center + "\nRadius: " + radius;
    }
}
