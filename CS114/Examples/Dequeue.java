package Examples;

import java.util.Random;

public class Dequeue {

    public static void main(String[] args) {

        Deque<Integer> deque = new Deque<Integer>();
        Random rand = new Random(1);

        System.out.println("insert");
        for (int i = 0; i < 10; ++i) {
            int n = rand.nextInt(10);
            deque.insertAtTail(n);
            System.out.println(n);
        }

        System.out.println("remove");
        try {
            while (true) {
                Integer m = deque.removeFromHead();
                System.out.println(m);
            }
        } catch (DequeException e) {
            System.out.println("done");
        }
    }
}

class Deque<E> {
    private Node<E> head;
    private Node<E> tail;

    private class Node<T> {
        private T data;
        private Node<T> next;
        private Node<T> prev;

        private Node(T data) {
            this.data = data;
        }

    }

    public void insertAtHead(E data) {
        Node<E> temp = new Node<E>(data);
        if (head == null) {
            head = tail = temp;
        } else {
            temp.next = head;
            head.prev = temp;
            head = head.prev;
        }
    }

    public void insertAtTail(E data) {
        Node<E> temp = new Node<E>(data);
        if (tail == null) {
            head = tail = temp;
        } else {
            temp.prev = tail;
            tail.next = temp;
            tail = tail.next;
        }
    }

    public E removeFromHead() throws DequeException {
        E temp = null;
        if (head == null) {
            throw new DequeException();
        } else if (head == tail) {
            temp = head.data;
            head = tail = null;
        } else {
            temp = head.data;
            head = head.next;
        }
        return temp;
    }

    public E removeFromTail() throws DequeException {
        E temp = null;
        if (tail == null) {
            throw new DequeException();
        } else if (head == tail) {
            temp = head.data;
            head = tail = null;
        } else {
            temp = tail.data;
            tail = tail.prev;
        }
        return temp;
    }

}

class DequeException extends Exception {
    public DequeException() {
    }

    public DequeException(String msg) {
        super(msg);
    }
}
