// Badr Abushaar
// CS113 Section 004
// Homework 01

import java.util.Scanner;

public class UnitConverter {
    public static void main(String[] args) {
        inchesToFeet();
        gramsToPounds();
        milligramConverter();

    }

    public static void inchesToFeet() {
        // Convert inches to feet
        float inches = 6;
        float feet = inches / 12;

        System.out.println(feet);
    }

    public static void gramsToPounds() {
        // Convert grams to pounds from user input
        float grams, pounds;

        Scanner scan = new Scanner(System.in);
        System.out.print("Enter the number of grams: ");
        grams = scan.nextFloat();

        pounds = grams / (float) 453.592;

        System.out.println(grams + " grams is equal to " + pounds + " pounds");
    }

    public static void milligramConverter() {
        // Convert milligrams to equivalent weights from user input
        int kilograms, grams, milligrams;

        Scanner scan = new Scanner(System.in);
        System.out.print("Enter the number of milligrams: ");
        int totalWeight = scan.nextInt();

        kilograms = totalWeight / 1000000;
        grams = (totalWeight - (kilograms * 1000000)) / 1000;
        milligrams = totalWeight - ((kilograms * 1000000) + (grams * 1000));

        System.out.println("Kilograms: " + kilograms);
        System.out.println("Grams: " + grams);
        System.out.println("milligrams: " + milligrams);
    }
}
