import java.util.Scanner;

public class TestBooks {
    public static void main(String [] args) {

        // Variables and object initialization
        System.out.println("Enter the amount of books to review: ");
        Scanner scan = new Scanner(System.in);
        int numOfBooks = scan.nextInt(), totalPages = 0;

        Book biggestBook = new Book(0, scan.nextLine());
        scan = new Scanner(System.in);

        // Create user specified book objects
        for (int count = 0; count < numOfBooks; count++) {

            System.out.println("Enter a publisher");
            Book book = new Book((int) (Math.random() * 100) + 1, scan.next());

            System.out.println("Pages: " + book.getPages() +"\n");
            totalPages += book.getPages();

            if (biggestBook.compareTo(book) != 1) {
                biggestBook = book;
            }
        }

        System.out.println(biggestBook);
        System.out.println("Average pages: " + (double) (totalPages / numOfBooks));
    }
}
