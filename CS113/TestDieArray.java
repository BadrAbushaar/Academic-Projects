public class TestDieArray {
    public static void main(String[] args) {

        Die[] dice = new Die[15];

        for (int index = 0; index < dice.length; index++)
            dice[index] = new Die();

        int total = 0;
        for (int index = 0; index < dice.length; index++) {
            dice[index].roll();
            if (dice[index].getFaceValue() == 3)
                total++;
        }

        for (Die d : dice)
            System.out.println(d + ", ");
    }
}
