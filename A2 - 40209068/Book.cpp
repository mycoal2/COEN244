#include "Book.h"
#include <string>

Book::Book() {
	publisher = "?";
	NumberOfPage = -1;
}
Book::Book(string title, string author, int year, string publisher, int NumberOfPage) :Reference(title, author, year) {
	this->publisher = publisher;
	this->NumberOfPage = NumberOfPage;
}
Book::Book(const Book& a) {
	setTitle(a.getTitle());
	setAuthor(a.getAuthor());
	setYear(a.getYear());
	this->publisher = a.getPublisher();
	this->NumberOfPage = a.getNumberOfPage();
}
Book::~Book() {

}

//getters
string Book::getPublisher() const {
	return publisher;
}
int Book::getNumberOfPage() const {
	return NumberOfPage;
}

//setters
void Book::setPublisher(string a) {
	publisher = a;
}
void Book::setNumberOfPage(int a) {
	NumberOfPage = a;
}

void Book::print() {
	Reference::print();
	cout << "Publisher: " << getPublisher() << endl;
	cout << "Numbers of page: " << getNumberOfPage() << endl;
	cout << endl;
}