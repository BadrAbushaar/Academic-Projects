public class PrintDigits {

    public static void printDigits(int num) {
        int i = num % 10;

        if (num == 0) {
            return;
        } else {
            printDigits(num / 10);
        }
        System.out.println(i);
    }
}