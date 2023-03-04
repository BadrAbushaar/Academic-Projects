package Examples;
// <expr> => <term> + <expr> | <term> - <expr> | <term>
// <term> => <numb> * <term> | <numb> / <term> | <numb>
// <numb> => 0 | 1 | ... | 8 | 9

public class Grammar {
    private static String s;
    private static int i;

    public static void main(String[] args) {
        s = args.length == 1 ? args[0] : "";
        if (expr() && i == s.length()) {
            System.out.println("The string \"" + s + "\" is in the language.");
        } else {
            System.out.println("The string \"" + s + "\" is not in the language.");
        }
    }

    public static boolean expr() {
        if (term()) {
            if (i < s.length() && (s.charAt(i) == '+' || s.charAt(i) == '-')) {
                ++i;
                if (expr()) {
                    return true;
                }
                return false;
            }
            return true;
        }
        return false;
    }

    public static boolean term() {
        if (numb()) {
            if (i < s.length() && (s.charAt(i) == '*' || s.charAt(i) == '/')) {
                ++i;
                if (term()) {
                    return true;
                }
                return false;
            }
            return true;
        }
        return false;
    }

    public static boolean numb() {
        if (i < s.length() && '0' <= s.charAt(i) && s.charAt(i) <= '9') {
            ++i;
            return true;
        }
        return false;
    }
}