#include "TextBook.h"
#include "Book.h"

TextBook::TextBook() {
	Web_Url = "?";
}

TextBook::TextBook(string title, string author, int year, string publisher, int NumberOfPage, string web) :Book(title, author, year, publisher, NumberOfPage) {
	Web_Url = web;
}
TextBook::TextBook(const TextBook& a) {
	setTitle(a.getTitle());
	setAuthor(a.getAuthor());
	setYear(a.getYear());
	setPublisher(a.getPublisher());
	setNumberOfPage(a.getNumberOfPage());
	Web_Url = a.getWeb_Url();
}
TextBook::~TextBook() {

}

string TextBook::getWeb_Url() const {
	return Web_Url;
}
void TextBook::setWeb_Url(string a) {
	Web_Url = a;
}
void TextBook::print() {
	Book::print();
	cout << "Web URL: " << getWeb_Url() << endl << endl;
}

