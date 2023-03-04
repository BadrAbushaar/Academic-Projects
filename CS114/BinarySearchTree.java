import java.util.Vector;
import java.util.Iterator;

public class BinarySearchTree<E extends Comparable<? super E>> extends BinaryTree<E> {
    private Vector<E> vector;

    public void insert(E data) {
        Node<E> node = new Node<E>(data);
        root = insert(root, node);
    }

    private Node<E> insert(Node<E> curr, Node<E> node) {
        // Empty tree
        if (curr == null) {
            curr = node;
            return curr;
        }

        // Node is less than current node
        if (node.data.compareTo(curr.data) <= 0) {
            if (curr.left == null) {
                curr.left = insert(curr.left, node);
                return curr;
            } else {
                insert(curr.left, node);
                return curr;
            }
            // Node is greater than current node
        } else {
            if (curr.right == null) {
                curr.right = insert(curr.right, node);
                return curr;
            } else {
                insert(curr.right, node);
                return curr;
            }
        }
    }

    public void remove(E data) {
        Node<E> curr = root;
        root = remove(data, curr);
    }

    private Node<E> remove(E data, Node<E> curr) {

        // Empty tree
        if (curr == null) {
            return curr;
        }

        // Data is less than root
        if (data.compareTo(curr.data) < 0) {
            curr.left = remove(data, curr.left);

            // Data is greater than root
        } else if (data.compareTo(curr.data) > 0) {
            curr.right = remove(data, curr.right);

            // Data is the one to remove
        } else {
            // Leaf Node
            if (curr.left == null && curr.right == null) {
                curr = null;
                return curr;
            }

            // Node has right Child
            if (curr.left == null) {
                return curr.right;

                // Node has left child
            } else if (curr.right == null) {
                return curr.left;

                // Node has two Children
            } else {
                Node<E> iop = findIOP(curr);
                E temp = iop.data;
                iop.data = curr.data;
                curr.data = temp;
                curr.left = remove(iop.data, curr.left);
                return curr;
            }
        }
        return curr;
    }

    public boolean search(E data) {
        Node<E> curr = root;
        return search(data, curr);
    }

    private boolean search(E data, Node<E> curr) {
        // Empty tree
        if (curr == null) {
            return false;
        }

        if (data.compareTo(curr.data) == 0) {
            return true;
        }

        // search left subtree
        if (data.compareTo(curr.data) <= 0) {
            return search(data, curr.left);
            // search right subtree
        } else if (data.compareTo(curr.data) > 0) {
            return search(data, curr.right);
        }

        return false;
    }

    public Iterator<E> iterator() {
        vector = new Vector<E>();
        traverse(root);
        return vector.iterator();
    }

    private void traverse(Node<E> curr) {
        if (curr != null) {
            traverse(curr.left);
            vector.add(curr.data);
            traverse(curr.right);
        }
    }

    private Node<E> findIOP(Node<E> curr) {
        curr = curr.left;
        while (curr.right != null) {
            curr = curr.right;
        }
        return curr;
    }
}