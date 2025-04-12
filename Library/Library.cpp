#include <iostream>
#include <string>
#include "Book.cpp"

using namespace std;
int main() {
    const int SIZE = 5;
    Book books[SIZE];

    // Initialize books
    books[0].setBookDetails("1984", "George Orwell", "9780451524935", "2023-02-01");
    books[1].setBookDetails("The Great Gatsby", "F. Scott Fitzgerald", "9780743273565", "2023-01-01");
    books[2].setBookDetails("To Kill a Mockingbird", "Harper Lee", "9780061120084", "2023-01-15");
    books[3].setBookDetails("Pride and Prejudice", "Jane Austen", "9780141439518", "2023-03-01");
    books[4].setBookDetails("Moby-Dick", "Herman Melville", "9781503280786", "2023-03-15");

    // Sort books by ISBN
    Book::sortBookData(books, SIZE);

    // Display sorted books
    cout << "\n--- Library Book List (Sorted by ISBN) ---\n";
    for (int i = 0; i < SIZE; ++i) {
        books[i].displayBookDetails();
    }

    // Borrowing loop
    string inputISBN;
    while (true) {
        cout << "\nEnter ISBN of the book to borrow (or 0 to exit): ";
        getline(cin, inputISBN);

        if (inputISBN == "0") {
            cout << "Exiting the program. Goodbye!\n";
            break;
        }

        bool found = false;
        for (int i = 0; i < SIZE; ++i) {
            if (books[i].getISBN() == inputISBN) {
                found = true;
                if (books[i].borrowBook()) {
                    cout << "Book borrowed successfully!\n";
                }
                else {
                    cout << "Error: Book is already borrowed.\n";
                }
                break;
            }
        }

        if (!found) {
            cout << " Error: Book with ISBN " << inputISBN << " not found.\n";
        }
    }

    return 0;
}