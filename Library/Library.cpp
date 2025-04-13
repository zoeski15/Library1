#include <iostream>
#include <string>
#include "Book.h"

using namespace std;
int main() {
    const int SIZE = 5;
    Book books[SIZE];

    // Initialize books
    books[0].setBookDetails("Fight Club", "Chuck Palahniuk", "9781784878542", "2025-04-01");
    books[1].setBookDetails("Lord of the Flies", "William Golding", "978-0399501487 ", "2025-04-02");
    books[2].setBookDetails("Demian", "Hermann Hesse", "9780143106784 ", "2025-04-03");
    books[3].setBookDetails("Normal People", "Sally Rooney", "9780571334650", "2025-04-04");
    books[4].setBookDetails("A Little Life", "Hanya Yanagihara", "9781447294832", "2025-04-05");

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
            cout << "End program\n";
            break;
        }

        bool found = false;
        for (int i = 0; i < SIZE; ++i) {
            if (books[i].getISBN() == inputISBN) {
                found = true;
                if (books[i].borrowBook()) {
                    cout << "Book borrowed\n";
                }
                else {
                    cout << "Error: Book has been borrowed.\n";
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