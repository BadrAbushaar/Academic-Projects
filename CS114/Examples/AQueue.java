package Examples;

import java.util.Iterator;

interface Queue<E> extends Iterable<E> {
    E dequeue();

    void enqueue(E data);
}

class AQueue<E> implements Queue<E> {
    private Object[] queue = new Object[10];
    private int head;
    private int tail;

    public void enqueue(E data) {
        if (head == (tail + 1) % queue.length) {
            grow();
        }

        queue[tail] = data;
        tail = (tail + 1) % queue.length;
    }

    public E dequeue() {
        if (queue.length > 10 && (queue.length + tail - head) % queue.length <= queue.length / 3) {
            shrink();
        }

        E temp = null;
        if (head != tail) {
            temp = (E) queue[head];
            head = (head + 1) % queue.length;
        }

        return temp;
    }

    public void grow() {
        Object[] temp = new Object[2 * queue.length];
        for (int i = 0; i < queue.length; ++i) {
            temp[i] = queue[(head + i) % queue.length];
        }

        head = 0;
        tail = queue.length - 1;
        queue = temp;
    }

    public void shrink() {
        Object[] temp = new Object[queue.length / 2];
        for (int i = 0; i < temp.length; ++i) {
            temp[i] = queue[(head + i) % queue.length];
        }

        head = 0;
        tail = queue.length / 3;
        queue = temp;
    }

    public Iterator<E> iterator() {
        return new QueueIterator<E>();
    }

    private class QueueIterator<E> implements Iterator<E> {
        private int curr = head;

        public boolean hasNext() {
            return curr < tail;
        }

        public E next() {
            return (E) queue[curr++];
        }
    }
}