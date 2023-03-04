package Examples;

import java.util.Iterator;

interface Stack<E> extends Iterable<E> {
    E pop();

    void push(E data);
}

public class AStack<E> implements Stack<E> {
    private int top;
    private Object[] stack = new Object[10];

    public E pop() {
        if (stack.length > 10 && top <= stack.length / 3) {
            shrink();
        }

        E temp = null;
        if (top > 0) {
            temp = (E) stack[--top];
        }
        return temp;
    }

    public void push(E data) {
        if (top >= stack.length) {
            grow();
        }
        stack[top++] = data;
    }

    private void grow() {
        Object[] temp = new Object[2 * stack.length];
        for (int i = 0; i < stack.length; ++i) {
            temp[i] = stack[i];
        }
        stack = temp;
    }

    private void shrink() {
        Object[] temp = new Object[stack.length / 2];
        for (int i = 0; i < temp.length; ++i) {
            temp[i] = stack[i];
        }
        stack = temp;
    }

    public Iterator<E> iterator() {
        return new StackIterator<E>();
    }

    private class StackIterator<E> implements Iterator<E> {
        private int curr = top;

        public boolean hasNext() {
            return curr > 0;
        }

        public E next() {
            return (E) stack[--curr];
        }
    }

}