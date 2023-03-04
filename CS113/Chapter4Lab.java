public class Chapter4Lab {

    public static double getBigAverage(Student studentOne, Student studentTwo) {
        return (double) (studentOne.getTest1() + studentTwo.getTest1() + studentOne.getTest2() + studentTwo.getTest2()) / 4;
    }

    public static void main(String[] args) {
        // Student Objects
        Student studentOne = new Student("John", 90, 85);
        Student studentTwo = new Student("Jill", 88, 98);

        // Student One
        String studentOneName = studentOne.getStudentName();
        int studentOneTest1 = studentOne.getTest1();
        int studentOneTest2 = studentOne.getTest2();
        double studentOneAverage = studentOne.average();

        // Student 2
        String studentTwoName = studentTwo.getStudentName();
        int studentTwoTest1 = studentTwo.getTest1();
        int studentTwoTest2 = studentTwo.getTest2();
        double studentTwoAverage = studentTwo.average();

        // Print student information
        System.out.println(studentOneName + "'s average: " + studentOneAverage);
        System.out.println(studentTwoName + "'s average: " + studentTwoAverage);

        System.out.println("Average of Midterm 2: " + (double) (studentOneTest2 + studentTwoTest2) / 2);

        System.out.println(studentOne.toString());
        System.out.println(studentTwo.toString());

        double totalAverage = getBigAverage(studentOne, studentTwo);
        System.out.println("Total average: " + totalAverage);
    }
}