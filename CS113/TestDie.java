public class TestDie {
    public static void main(String[] args) {
        // Create 2 dice
        // Roll die and print their face value

        Die dieOne = new Die(); // Value is the address/reference
        Die dieTwo = new Die(5);
        Die dieThree = new Die();

        System.out.println(dieOne.equals(dieTwo));

        System.out.println("Roll one: " + dieOne.getFaceValue() + ", " + dieTwo.getFaceValue());
        System.out.println("Sum Roll One: " + (dieOne.getFaceValue() + dieTwo.getFaceValue()));

        dieOne.roll();
        dieTwo.setFaceValue(3);

        System.out.println("-- Dice Rolled --");
        System.out.println("Roll two: " + dieOne.getFaceValue() + ", " + dieTwo.getFaceValue());
        System.out.println(dieOne + ", " + dieTwo);

        int total = 0;
        for (int rolls = 0; rolls <= 100; rolls++) {
            dieThree.roll();
            if (dieThree.getFaceValue() == 3) {
                total++;
            }
        }
        System.out.println("Rolling 3: " + total);
    }
}