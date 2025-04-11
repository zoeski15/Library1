
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
			cout << "Title" << title << endl;
			cout << "Author" << author << endl;
			cout << "isbn" << isbn << endl;
			cout << "Availability" << (availability ? "Available" : "Borrowed") << endl;
			cout << "Date Added" << dateAdd << endl;
			cout << "------" << endl;

		}
	};

	return 0;
}


