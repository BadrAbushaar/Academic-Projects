import java.util.Scanner;

public class MainThrow {
    public static void main(String[] args) throws BonusTooLowException {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter array size: ");
        int arrSize = scan.nextInt();
        Executive[] execArr = new Executive[arrSize];
        BonusTooLowException problem = new BonusTooLowException("Bonus value is less than $2000.");

        for (Executive exec : execArr) {
            System.out.println("Enter name, address, phone, SSN, payrate, and bonus: ");
            scan = new Scanner(System.in);
            scan.next();

            String name = scan.next();
            String address = scan.next();
            String phone = scan.next();
            String ssn = scan.next();
            double payrate = scan.nextDouble();
            double bonus = scan.nextDouble();

            scan.close();

            exec = new Executive(name, address, phone, ssn, payrate);

            if (bonus < 2000)
                throw problem;

            exec.awardBonus(bonus);

        }
    }
}