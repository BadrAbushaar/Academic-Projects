// Badr Abushaar
// CS113 Section 004
// Homework 02

import java.util.Scanner;
import java.util.Random;

public class NameApp {
    public static void main(String[] args) {
        // Generates username based on user input
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter your first name: ");
        String firstName = scan.next();
        System.out.println("Enter your last name: ");
        String lastName = scan.next();

        Random gen = new Random();
        int randomNumber = gen.nextInt(0, 50);

        System.out.println(lastName.charAt(0) + firstName.substring(0, 3) + randomNumber);
    }
}
