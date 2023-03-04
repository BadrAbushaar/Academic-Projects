import java.util.Scanner;

public class Kennel {
    public static void main(String[] args) {
        // Instantiation
        Dog dogOne = new Dog();
        Dog dogTwo = new Dog();

        // Update Dog objects with user input
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter the first dog's age: ");
        dogOne.setDogAge(scan.nextInt());
        System.out.println("Enter the first dog's name: ");
        dogOne.setDogName(scan.next());
        System.out.println("Enter the second dog's age: ");
        dogTwo.setDogAge(scan.nextInt());
        System.out.println("Enter the second dog's name: ");
        dogTwo.setDogName(scan.next());

        // Display Dog object information
        System.out.println(dogOne.toString());
        System.out.println(dogTwo.toString());
        int totalDogAge = dogOne.getDogAge() + dogTwo.getDogAge();
        System.out.println("The average age in human years is: " +
                (dogOne.toPersonYears() + dogTwo.toPersonYears()) / 2);
    }
}