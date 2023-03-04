import java.util.Scanner;

public class Chapter5Lab {
    public static void main(String[] args) {
        // 1
        System.out.println("I love CS");

        // 2
        System.out.println("Enter a number: ");
        Scanner scan = new Scanner(System.in);
        int num = scan.nextInt();
        System.out.println(Math.pow(num, 2));

        // 3
        System.out.println("Enter a new number: ");
        int result = 1;
        int factNum = scan.nextInt();
        while (factNum > 0) {
            result = result * factNum;
            factNum--;
        }
        System.out.println(result);
        // 4


    }
}