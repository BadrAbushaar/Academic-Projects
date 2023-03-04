public class Student {

    private String name;
    private GPA gpa;

    public Student(String name, GPA gpa) {
        this.name = name;
        this.gpa = gpa;
    }

    public GPA getGPA() {
        return gpa;
    }

    public void setName(String name) {
        this.name = name;
    }

    public boolean honorRoll(GPA gpa) {
        if (this.gpa.compareTo(gpa) == 1 || this.gpa.compareTo(gpa) == 0)
            return true;
        else
            return false;
    }

    public String toString() {
        return "Name: " + this.name + "\nGPA: " + this.gpa;
    }
}
