// Badr Abushaar
// CS113 Section 004
// Homework 02

import java.util.Scanner;

public class NameAverage {
    public static void main(String[] args) {
        // Finds the average name length of four names from user input
        Scanner scan = new Scanner(System.in);
        String studentOne, studentTwo, studentThree, studentFour;

        System.out.println("Enter the first student's name: ");
        studentOne = scan.next();
        System.out.println("Enter the second student's name: ");
        studentTwo = scan.next();
        System.out.println("Enter the third student's name: ");
        studentThree = scan.next();
        System.out.println("Enter the fourth student's name: ");
        studentFour = scan.next();

        int totalNameLength = studentOne.length() + studentTwo.length() + studentThree.length() + studentFour.length();
        double averageLength = totalNameLength / 4.0;

        System.out.println(averageLength);
        System.out.print(studentOne.charAt(0));
        System.out.print(studentTwo.charAt(0));
        System.out.print(studentThree.charAt(0));
        System.out.print(studentFour.charAt(0));
    }
}
