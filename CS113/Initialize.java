public class Initialize {

    public static int[][] initialize(int[][] arr) {
        for (int row = 0; row < arr.length; row++) {
            for (int column = 0; column < arr[row].length; column++) {
                if (row == column) {
                    arr[row][column] = -1;
                } else {
                    arr[row][column] = row + column;
                }
            }
        }
        return arr;
    }
}
