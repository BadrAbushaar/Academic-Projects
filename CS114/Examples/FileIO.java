package Examples;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class FileIO {
    public static void main(String[] args) {
        File in = new File("Main.java");
        File out = new File("copy.txt");
        try (Scanner scan = new Scanner(in);
                PrintWriter pw = new PrintWriter(out)) {
            while (scan.hasNext()) {
                pw.println(scan.nextLine());
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}