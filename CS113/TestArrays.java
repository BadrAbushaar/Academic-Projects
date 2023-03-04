import java.util.Arrays;
import java.util.Scanner;

public class TestArrays {

    public static int[] numberFreq() {
        Scanner scan = new Scanner(System.in);

        System.out.println("How many numbers would you like to enter? ");
        int numOfNumbers = scan.nextInt();
        int[] freqArray = new int[50];

        for (int index = 0; index < numOfNumbers; index++) {
            System.out.println("Enter a number between 0 and 50, inclusive.");
            int userNumber = scan.nextInt();
            if (userNumber >= 0 && userNumber <= 50) {
                freqArray[userNumber] += 1;
            } else {
                index--;
                System.out.println("Invalid number. Please enter a number between 0 and 50, inclusive.");
            }
        }
        return freqArray;
    }

    public static int bigEven(int[] numArray, int target) {
        int total = 0;
        for (int num : numArray) {
            if (num % 2 == 0 && num > target) {
                total += 1;
            }
        }
        return total;
    }

    public static int oddDice(Die[] diceArray) {
        int total = 0;
        for (Die die : diceArray) {
            if (die.getFaceValue() % 2 != 0)  {
                total += 1;
            }
        }
        return total;
    }

    public static void main(String[] args) {
        System.out.println(Arrays.toString(TestArrays.numberFreq()));
        System.out.println("Numbers bigger than target number: " + TestArrays.bigEven(new int[]{10, 12, 14, 16}, 12));
        System.out.println("Dice that landed on odd value: " + TestArrays.oddDice(new Die[]{new Die(), new Die(), new Die(3), new Die(2)}));
    }
}







