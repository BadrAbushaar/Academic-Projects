import java.util.Scanner;

public class TestEV {
    public static void main(String[] args) {
        System.out.println("Enter a range: ");
        Scanner scan = new Scanner(System.in);
        int userRange = scan.nextInt();

        System.out.println("Enter a model: ");
        scan = new Scanner(System.in);
        String userModel = scan.next();

        EV ev1 = new EV(userRange, userModel);
        EV ev2 = new EV((int) (Math.random() * 51) + 250, "Tesla Model S");

        if (ev1.compareTo(ev2) == 1) {
            System.out.println("\n" + ev1);
        } else if (ev1.compareTo(ev2) == 0) {
            System.out.println("\nsame");
        } else {
            System.out.println("\n" + ev2);
        }

        System.out.println("Same model?: " + ev1.sameModel(ev2));
    }
}
