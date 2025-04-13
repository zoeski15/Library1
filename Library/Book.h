#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;
    bool availability;
    string dateAdd;

public:
    // Set book details
    void setBookDetails(string t, string a, string i, string d) {
        title = t;
        author = a;
        isbn = i;
        availability = true;  // Default: available when added
        dateAdd = d;
    }

    // Display book details
    void displayBookDetails() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Availability: " << (availability ? "Available" : "Borrowed") << endl;
        cout << "Date Added: " << dateAdd << endl;
        cout << "---------------------------" << endl;
    }

    // Get ISBN
    string getISBN() const {
        return isbn;
    }

    // Check availability
    bool isAvailable() const {
        return availability;
    }

    // Borrow book
    bool borrowBook() {
        if (availability) {
            availability = false;
            return true;
        }
        else {
            return false;
        }
    }

    // Return book
    void returnBook() {
        availability = true;
    }

    // Static method to sort an array of Book objects by ISBN
    static void sortBookData(Book books[], int size) {
        for (int i = 0; i < size - 1; ++i) {
            for (int j = i + 1; j < size; ++j) {
                if (books[i].getISBN() > books[j].getISBN()) {
                    swap(books[i], books[j]);
                }
            }
        }
    }
};