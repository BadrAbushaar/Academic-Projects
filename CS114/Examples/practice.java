package Examples;

public class practice {

    public static <T extends Comparable<? super T>> void bubbleSort(T[] array) {
        T temp;
        boolean sorted;

        int n = array.length;

        for (int i = n - 1; i > 0; --i) {
            sorted = true;

            for (int j = 0; j < i; ++j) {
                if (array[j].compareTo(array[j + 1]) > 0) {
                    sorted = false;

                    temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
            if (sorted) {
                break;
            }
        }
    }
}
