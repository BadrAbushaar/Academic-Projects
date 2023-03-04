package Examples;

import java.util.Iterator;

interface Stack<E> extends Iterable<E> {
    E pop();

    void push(E data);
}

public class RStack<E> implements Stack<E> {
    private Node<E> head;

    private class Node<T> {
        private T data;
        private Node<T> next;

        private Node(T data) {
            this.data = data;
        }
    }

    public E pop() {
        E temp = null;
        if (head != null) {
            temp = head.data;
            head = head.next;
        }
        return temp;
    }

    public void push(E data) {
        Node<E> temp = new Node<E>(data);
        temp.next = head;
        head = temp;
    }

    public Iterator<E> iterator() {
        return new Iterator<E>() {
            Node<E> curr = head;

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