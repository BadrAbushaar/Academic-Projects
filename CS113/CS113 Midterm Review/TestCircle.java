import java.util.Scanner;

public class TestCircle {
    public static void main(String[] args) {
        System.out.println("Enter a radius");
        Scanner scan = new Scanner(System.in);
        int userRadius = scan.nextInt();
        scan.close();

        Circle circle1 = new Circle(userRadius);
        System.out.println("Circle 1 radius: " + circle1.getRadius());
        Circle circle2 = new Circle((int) (Math.random() * 11) + 5);
        System.out.println("Circle 2 radius: " + circle2.getRadius());

        double circle1Area = circle1.area();
        double circle2Area = circle2.area();
        System.out.println("Circle 1 area: " + circle1Area);
        System.out.println("Circle 2 area: " + circle2Area);

        int radius1 = circle1.getRadius();
        int radius2 = circle2.getRadius();
        circle1.setRadius(radius2);
        circle2.setRadius(radius1);

        System.out.println("Circle 1: " + circle1);
        System.out.println("Circle 2: " + circle2);
    }

}