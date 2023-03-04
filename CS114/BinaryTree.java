public abstract class BinaryTree<E> implements Iterable<E> {

    protected Node<E> root;

    public abstract void insert(E data);

    public abstract void remove(E data);

    public abstract boolean search(E data);

    protected class Node<T> {

        protected T data;
        protected Node<T> left;
        protected Node<T> right;

        protected Node(T data) {
            this.data = data;
        }
    }
}
