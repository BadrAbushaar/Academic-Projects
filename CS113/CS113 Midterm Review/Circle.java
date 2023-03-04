public class Circle {

    private Point center;
    private float radius;

    public Circle(Point center, float radius) {
        this.center = center;
        this.radius = radius;
    }

    public Point getCenter() {
        return center;
    }

    public void setRadius(float radius) {
        this.radius = radius;
    }

    public boolean liesOnCircle(Point point) {
        return center.distance(point) == radius;
    }
}
