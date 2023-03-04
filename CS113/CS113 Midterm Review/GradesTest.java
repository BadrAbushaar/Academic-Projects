import java.util.*;

public class GradesTest {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        System.out.println("Enter a score: ");
        int userScore = scan.nextInt();
        Grade entry = new Grade(userScore);

        Grade grade = new Grade((int) (Math.random() * 61) + 40);
        System.out.println(grade);
        int count = 0;

        while (grade.equals(entry)) {
            if (grade.getNumGrade() > entry.getNumGrade()) {
                count++;
            }
            grade = new Grade((int) (Math.random() * 61) + 40);
            System.out.println(grade);
        }
        System.out.println(count);
    }
}
