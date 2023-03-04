public class HeapSort {

    public static <T extends Comparable<? super T>> void heapSort(T[] array) {
        int length = array.length;

        // Rearrage the array
        for (int i = length / 2 - 1; i >= 0; i--) {
            heapify(array, i, length);
        }

        // Move root to end and remove from heap
        for (int i = length - 1; i >= 0; i--) {
            T swap = array[0];
            array[0] = array[i];
            array[i] = swap;

            // Reheapify on smaller heap
            heapify(array, 0, i);
        }
    }

    // Heapify subtree rooted at "root"
    private static <T extends Comparable<? super T>> void heapify(T[] array, int root, int length) {

        int max = root;
        int leftChild = (root * 2) + 1;
        int rightChild = (root * 2) + 2;

        if (leftChild < length && array[leftChild].compareTo(array[max]) > 0) {
            max = leftChild;
        }

        if (rightChild < length && array[rightChild].compareTo(array[max]) > 0) {
            max = rightChild;
        }

        if (max != root) {
            T swap = array[root];
            array[root] = array[max];
            array[max] = swap;

            // Reheapify subtree
            heapify(array, max, length);
        }
    }
}
