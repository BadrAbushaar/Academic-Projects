import java.util.*;

public class CircleTest {
    public static void main(String[] args) {
        Circle[] circleArr = new Circle[50];
        Scanner scan = new Scanner(System.in);

        for (int i = 0; i < 50; i++) {
            int x = scan.nextInt();
            int y = scan.nextInt();
            float z = scan.nextFloat();
            Point center = new Point(x, y);
            circleArr[i] = new Circle(center, z);
        }

        scan.close();

        int count = 0;
        Point origin = new Point(0, 0);
        for (int i = 0; i < 50; i++) {
            if (circleArr[i].liesOnCircle(origin) == true) {
                count++;
            }
        }
        System.out.println(count);
    }
}
