#include "Article.h"

Article::Article() {
	journal = "?";
	starPage = -1;
	endPage = -1;
}
Article::Article(string title, string author, int year, string journal, int starpage, int endpage):Reference(title, author,year) {
	this->journal = journal;
	this->starPage = starpage;
	this->endPage = endpage;
}
Article::Article(const Article& a) {
	setTitle(a.getTitle());
	setAuthor(a.getAuthor());
	setYear(a.getYear());
	this->journal = a.getJournal();
	this->starPage = a.getstarPage();
	this->endPage = a.getendPage();
}
Article::~Article() {

}

//getters
string Article::getJournal() const {
	return journal;
}
int Article::getstarPage() const {
	return starPage;
}
int Article::getendPage() const {
	return endPage;
}
int Article::getNumberOfPages() const {
	return (getendPage() - getstarPage());
}

//setters
void Article::setJournal(string a) {
	journal = a;
}
void Article::setstarPage(int a) {
	starPage = a;
}
void Article::setendPage(int a) {
	endPage = a;
}

void Article::print() {
	Reference::print();
	cout << "Journal: " << getJournal() << endl;
	cout << "Starts at page: " << getstarPage() << endl;
	cout << "Ends at page: " << getendPage() << endl;
	cout << endl;
}