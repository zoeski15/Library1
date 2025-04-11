#include <iostream>
#include <string>

using namespace std;

int main() {

class Book {
private:
	string title;
	string author;
	string isbn;
	bool availability;
	string dateAdd;

public:
	Book() : title(""), author(""), isbn(""), availability(true), dateAdd("") {}

	void setBookDetails(string t, string a, string i, string d) {
		title = t;
		author = a;
		isbn = i;
		availability = true;
		dateAdd = d;
	}

	void displayBookDetails() const {
		cout << "Title: " << title << endl;
		cout << "Author: " << author << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "Availability: " << (availability ? "Available" : "Borrowed") << endl;
		cout << "Date Added: " << dateAdd << endl;
		cout << "------" << endl;
	}

	string getisbn() const {
		return isbn;
	}

	bool isAvailable() const{
		return availability;
	}

	bool hasBeenBorrowed() {
		if(availability) {
			availability = false;
			return true;
		}
		return false;
	   }
	void returnBook() {
		availability = true;
	}
};

return 0;
}
