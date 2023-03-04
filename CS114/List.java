public abstract class List<E> implements Iterable<E> {
    protected Node<E> head;

    protected class Node<T> {
        protected T data;
        protected Node<T> next;

        protected Node(T data) {
            this.data = data;
        }

    }

    public abstract void insert(E data);

    public abstract void remove(E data);

    public abstract E retrieve(int index);

    public abstract boolean search(E data);
}