public class Student {
    private String studentName;
    private int test1, test2;

    public Student() {
        studentName = "";
        test1 = 0;
        test2 = 0;
    }

    public Student(String nameOfStudent, int testOne, int testTwo) {
        studentName = nameOfStudent;
        test1 = testOne;
        test2 = testTwo;
    }

    // Mutators
    public void setStudentName(String name) { studentName = name; }
    public void setTest1(int testScore) { test1 = testScore; }
    public void setTest2(int testScore) { test2 = testScore; }

    // Accessors
    public String getStudentName() { return studentName; }
    public int getTest1() { return test1; }
    public int getTest2() { return test2; }

    // Average method
    public double average() {
        return (double) (test1 + test2) / 2;
    }

    // toString
    public String toString() { return studentName + "'s Scores: \nTest 1: " + test1 + "\nTest2: " + test2; }

    // Big average method
    public double getBigAverage(Student studentOne, Student studentTwo) {
        return (double) (studentOne.test1 + studentTwo.test1 + studentOne.test2 + studentTwo.test2) / 4;
    }
}