public class Book {
    // Instance data
    private int pages;
    private String publisher;

    // Constructor
    public Book(int bookPages, String bookPublisher) {
        pages = bookPages;
        publisher = bookPublisher;
    }

    // Accessors
    public int getPages() { return pages; }
    public String getPublisher() { return publisher; }

    // Mutators
    public void setPages(int newPages) { pages = newPages; }
    public void setPublisher(String newPublisher) { publisher = newPublisher; }

    // toString method
    public String toString() { return "The biggest book is published by " + publisher + " and has " + pages + " pages."; }

    // Equals method
    public boolean equals(Book otherBook) {
        if (pages == otherBook.getPages() && publisher.equals(otherBook.getPublisher())) {
            return true;
        } else {
            return false;
        }
    }

    // compareTo method
    public int compareTo(Book otherBook) {
        if (this.getPages() == otherBook.getPages()) {
            return 0;
        } else if (this.getPages() < otherBook.getPages()) {
            return -1;
        } else {
            return 1;
        }
    }
}