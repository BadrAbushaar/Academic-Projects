public class Recursion {

    public int factorial(int n) {
        int answer;

        if (n == 1)
            answer = 1;
        else
            answer = n * factorial(n-1);

        return answer;
    }
}
