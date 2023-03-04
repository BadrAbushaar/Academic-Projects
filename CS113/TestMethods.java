public class TestMethods {
    public static void main(String[] args) {
        MyMethods testCase1 = new MyMethods();
        Die dieOne = new Die();
        Die dieTwo = new Die();

        int surfaceArea = testCase1.surface();
        System.out.println(surfaceArea);

        double average = testCase1.avgFaceValues(dieOne, dieTwo);
        System.out.println("Face Value 1: " + dieOne.getFaceValue());
        System.out.println("Face Value 2: " + dieTwo.getFaceValue());
        System.out.println(average);

    }
}