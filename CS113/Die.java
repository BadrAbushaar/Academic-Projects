public class Die {
    // Data declaration
    private int faceValue;
    private final int MAX = 6;

    public Die() {
        roll();
    }

    // Non-default constructor
    public Die(int newFace) {
        faceValue = newFace;
    }

    // Roll method
    public void roll() { faceValue = (int)(Math.random() * 6) + 1; }

    // Getter method
    public int getFaceValue() {
        return faceValue;
    }

    // Setter method
    public void setFaceValue(int face) {
        faceValue = face;
    }

    // toString method
    public String toString() {
        return "" + faceValue;
    }

    // Equals method
    public boolean equals(Die other) {
        if (faceValue == other.getFaceValue())
            return true;
        else
            return false;
    }

    // Compare method
    public static int compareTo(Die dieOne, Die dieTwo) {
        int value1 = 0, value2 = 1;
        int count = 0;
        while (value1 != value2) {
            dieOne.roll();
            dieTwo.roll();
            value1 = dieOne.getFaceValue();
            value2 = dieTwo.getFaceValue();
            count++;
        }
        return count;
    }
}