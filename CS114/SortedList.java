import java.util.Iterator;

public class SortedList<E extends Comparable<? super E>> extends List<E> {

    // Insert method
    public void insert(E data) {
        Node<E> curr = head;
        head = insert(data, curr);
    }

    // Insert helper method
    private Node<E> insert(E data, Node<E> curr) {
        // Empty list
        if (curr == null) {
            Node<E> temp = new Node<E>(data);
            curr = temp;
            temp.next = null;
            return curr;
        }

        if (data.compareTo(curr.data) < 0) {
            Node<E> temp = new Node<E>(data);
            temp.next = curr;
            curr = temp;
            return curr;
        } else {
            curr.next = insert(data, curr.next);
            return curr;
        }
    }

    // Remove method
    public void remove(E data) {
        Node<E> curr = head;
        head = remove(data, curr);
    }

    // Remove helper method
    private Node<E> remove(E data, Node<E> curr) {
        if (curr == null) {
            return null;
        }

        if (data.compareTo(curr.data) == 0) {
            curr = curr.next;
            return curr;
        } else {
            curr.next = remove(data, curr.next);
            return curr;
        }
    }

    // Retrieve method
    public E retrieve(int index) {
        Node<E> curr = head;
        int count = 0;
        return retrieve(index, curr, count);
    }

    // Retrieve helper method
    private E retrieve(int index, Node<E> curr, int count) {
        if (curr == null) {
            return null;
        }

        if (index == count) {
            return curr.data;
        } else {
            return retrieve(index, curr.next, count + 1);
        }
    }

    // Search method
    public boolean search(E data) {
        Node<E> curr = head;
        return search(data, curr);
    }

    // Search helper method
    private boolean search(E data, Node<E> curr) {
        if (curr == null) {
            return false;
        }

        if (data.compareTo(curr.data) == 0) {
            return true;
        } else {
            return search(data, curr.next);
        }
    }

    // Iterator method
    public Iterator<E> iterator() {
        return new Iterator<E>() {
            private Node<E> curr = head;

            public boolean hasNext() {
                return curr != null;
            }

            public E next() {
                E temp = curr.data;
                curr = curr.next;
                return temp;
            }

        };
    }
}