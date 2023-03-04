import java.util.Scanner;

public class TestCircle {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter a radius: ");
        int radius = scan.nextInt();

        // Point objects
        Point point1 = new Point((int) (Math.random() * 25) + 1, (int) (Math.random() * 25) + 1);
        Point point2 = new Point(0, 0);

        // Circle objects
        Circle circle1 = new Circle(point2, radius);
        Circle circle2 = new Circle(point1, 10);

        System.out.println("--Circle 1-- \n" + circle1.toString() + "\nArea: " + circle1.area());
        System.out.println("--Circle 2-- \n" + circle2.toString() + "\nArea: " + circle2.area());

        if (circle1.equals(circle2)) {
            System.out.println("Distance: " + circle1.getCenter().distance(circle2.getCenter()));
        } else {
            System.out.println("Average area: " + (circle1.area() + circle2.area()) / 2);
        }
    }
}
