package Examples;
//      60

//     /  \
//   20    70
//   / \
// 10   40
//     /  \
//   30    50

public class Order {
    private static Node root;

    private static class Node {
        private int data;
        private Node left;
        private Node right;

        private Node(int data) {
            this.data = data;
        }

    }

    public static void main(String[] args) {
        root = new Node(60);
        root.left = new Node(20);
        root.right = new Node(70);
        root.left.left = new Node(10);
        root.left.right = new Node(40);
        root.left.right.left = new Node(30);
        root.left.right.right = new Node(50);

        System.out.print("pre: ");
        preorder(root);
        System.out.print("\nin:  ");
        inorder(root);
        System.out.print("\npost:");
        postorder(root);
        System.out.println();
    }

    private static void inorder(Node curr) {
        if (curr != null) {
            inorder(curr.left);
            System.out.print(curr.data + " ");
            inorder(curr.right);
        }
    }

    private static void postorder(Node curr) {
        if (curr != null) {
            postorder(curr.left);
            postorder(curr.right);
            System.out.print(curr.data + " ");
        }
    }

    private static void preorder(Node curr) {
        if (curr != null) {
            System.out.print(curr.data + " ");
            preorder(curr.left);
            preorder(curr.right);
        }
    }
}
