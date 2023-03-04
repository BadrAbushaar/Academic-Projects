public class SumArray {

    public static int sumArray(int[] numArray, int numbersToAdd) {
        int sum = 0;

        if (numbersToAdd == 0)
            return 0;
        else {
            sum += numArray[numbersToAdd - 1];
            sum += sumArray(numArray, numbersToAdd - 1);
        }
        return sum;
    }
}