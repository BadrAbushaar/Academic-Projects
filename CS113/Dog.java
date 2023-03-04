public class Dog {
    private int dogAge;
    private String dogName;

    // Default constructor
    public Dog() {
        dogName = "dog";
        dogAge = 0;
    }

    // Getter methods
    public int getDogAge() {
        return dogAge;
    }
    public String getDogName() {
        return dogName;
    }

    // Setter methods
    public void setDogAge(int age) {
        dogAge = age;
    }
    public void setDogName(String name) {
        dogName = name;
    }

    // Returns age in human years
    public int toPersonYears() {
        return dogAge * 7;
    }

    // toString method
    public String toString() {
        return dogName + " is " + dogAge + " years old!";
    }
}