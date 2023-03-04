public class Midterm2Practice3 {

    public static double[] bestInMonths(double[][] famCellBills) {
        int months = famCellBills[0].length;
        double[] bestBill = new double[months];

        for (int month = 0; month < months; month++) {
            double lowest = famCellBills[0][month];

            for (int member = 0; member < famCellBills.length; member++) {
                if (famCellBills[member][month] < lowest) {
                    lowest = famCellBills[member][month];
                }
            }
            bestBill[month] = lowest;
        }
        return bestBill;
    }
}
