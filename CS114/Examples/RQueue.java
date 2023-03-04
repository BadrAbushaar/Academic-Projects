package Examples;

import java.util.Iterator;

interface Queue<E> extends Iterable<E> {
    E dequeue();

    void enqueue(E data);
}

class RQueue<E> implements Queue<E> {
    private Node<E> head;
    private Node<E> tail;

    private class Node<T> {
        private T data;
        private Node<T> next;

        private Node(T data) {
            this.data = data;
        }
    }

    public void enqueue(E data) {
        Node<E> temp = new Node<E>(data);
        if (head == null) {
            head = tail = temp;
        } else {
            tail.next = temp;
            tail = tail.next;
        }
    }

    public E dequeue() {
        E temp = null;
        if (head != null) {
            temp = head.data;
            if (head == tail) {
                head = tail = null;
            } else {
                head = head.next;
            }
        }

        return temp;
    }

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