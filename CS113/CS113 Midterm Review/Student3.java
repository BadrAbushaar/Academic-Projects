public class Student3 {
    private int finalScore;

    public Student3(int finalScore) {
        this.finalScore = finalScore;
    }

    public void setFinalScore(int f) {
        finalScore = f;
    }

    public int getFinalScore() {
        return finalScore;
    }

}

public Course(int size) {
    stdList = new Student3[size];
    stats = new int[10];

    for (Student student : stdList) {
    }

    for (int i = 0; i < size; i++) {
        stdList[i] = new Student(setFinalScore((int) (Math.random() * 100) + 1));
        int finalScore = stdList[i].getFinalScore();
        if (finalScore > 90) {
            stats[(finalScore - 1) % 10]++;
        }
    }
}