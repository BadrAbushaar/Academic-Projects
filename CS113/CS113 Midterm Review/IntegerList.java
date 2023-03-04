import java.util.*;

public class IntegerList {

    private int[] array;

    public IntegerList(int size) {
        array = new int[size];
    }

    public int[] getArray() {
        return array;
    }

    public void setArray(int[] array) {
        this.array = array;
    }

    public void randomize() {
        Random rand = new Random();
        for (int i = 0; i < array.length; i++) {
            array[i] = rand.nextInt(100) + 1;
        }
    }

    public String toString() {
        String s = "";
        for (int i = 0; i < array.length; i++) {
            s = s + array[i] + " ";
        }
        return s;
    }

    public int[] merge(int[] other) {
        int[] result = new int[array.length + other.length];

        for (int i = 0; i < array.length; i++) {
            result[i] = array[i];
        }

        for (int i = 0; i < other.length; i++) {
            result[array.length + i] = other[i];
        }

        return result;
    }
}
