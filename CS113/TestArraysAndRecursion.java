import java.util.Arrays;

public class TestArraysAndRecursion {
    public static void printRow(int[] row) {
        for (int i : row) {
            System.out.print(i);
            System.out.print("\t");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        // initialize test
        System.out.println("initialize Test:");
        int[][] twoArr = Initialize.initialize(new int[4][4]);
        for(int[] row : twoArr)
            printRow(row);

        // dieStats test
        System.out.println("\ndieStats Test:");
        Die[][] dieArr = new Die[2][3];
        for (int i = 0; i < dieArr.length; i++)
            for (int j = 0; j < dieArr[i].length; j++)
                dieArr[i][j] = new Die();
        int[] dieArrEven = DieStats.dieStats(dieArr);
        System.out.println(Arrays.toString(dieArrEven));

        // printDigits test
        System.out.println("\nprintDigits Test:");
        PrintDigits.printDigits(35);

        // sumArray test
        System.out.println("\nsumArray Test:");
        int[] arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        System.out.println(SumArray.sumArray(arr, 4));
    }
}
