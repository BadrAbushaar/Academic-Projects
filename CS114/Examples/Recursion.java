package Examples;

public class Recursion {
    public static void main(String[] args) {
        tower(Integer.parseInt(args[0]), 'A', 'C', 'B');
    }

    public static int choose(int n, int k) {
        if (k > n) {
            return 0;
        } else if (k == 0 || k == n) {
            return 1;
        }
        return choose(n - 1, k - 1) + choose(n - 1, k);
    }

    public static int fact(int n) {
        if (n == 0) {
            return 1;
        }
        return n * fact(n - 1);
    }

    public static int fibo(int n) {
        if (n == 0 || n == 1) {
            return n;
        }
        return fibo(n - 1) + fibo(n - 2);
    }

    public static int pow(int x, int n) {
        if (n == 0) {
            return 1;
        } else if (n % 2 == 0) {
            return pow(x * x, n / 2);
        } else {
            return x * pow(x * x, n / 2);
        }
    }

    public static String reverse(String s) {
        if (s.length() > 0) {
            return reverse(s.substring(1)) + s.charAt(0);
        }
        return s;
    }

    public static int sum(int n) {
        if (n == 0) {
            return 0;
        }
        return n + sum(n - 1);
    }

    public static void tower(int n, char src, char dst, char use) {
        if (n > 0) {
            tower(n - 1, src, use, dst);
            System.out.println("Move disk " + n + " from " + src + " to " + dst);
            tower(n - 1, use, dst, src);
        }
    }
}