public class DieStats {

    public static int[] dieStats(Die[][] dice) {
        int[] evenDie = new int[dice.length];

        for (int dieRow = 0; dieRow < dice.length; dieRow++) {
            int rowTotal = 0;
            for (int die = 0; die < dice[dieRow].length; die++) {
                dice[dieRow][die].roll();
                if (dice[dieRow][die].getFaceValue() % 2 == 0) {
                    rowTotal += 1;
                }
            }
            evenDie[dieRow] = rowTotal;
        }
        return evenDie;
    }
}