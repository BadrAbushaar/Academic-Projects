import java.util.Scanner;

public class MyMethods {
    public int surface() {
        int width, length, height;
        Scanner scan = new Scanner(System.in);

        System.out.println("Enter width: ");
        width = scan.nextInt();
        System.out.println("Enter length: ");
        length = scan.nextInt();
        System.out.println("Enter width: ");
        height = scan.nextInt();

        return ((2 * (width * height)) + (2 * (width * length)) + (2 * (height * length)));
    }

    public double avgFaceValues(Die die1, Die die2) {
        return (double) (die1.getFaceValue() + die2.getFaceValue()) / 2;
    }
}