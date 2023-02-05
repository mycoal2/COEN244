#include "Reference.h"


int Reference::uniqueID;
Reference::Reference() {              //default constructor
    ID = uniqueID;
    title = "?";
    author = "?";
    year_publication = -1;
}
Reference::Reference(string title, string author, int year) {   
    uniqueID++;
    ID = uniqueID;
    this->title = title;
    this->author = author;
    year_publication = year;
}
Reference::Reference(const Reference& ref) {    //copy constructor
    ID = ref.getID();
    this->title = ref.getTitle();
    this->author = ref.getAuthor();
    year_publication = ref.getYear();
}
Reference::~Reference() {   

}

//getters
int Reference::getID() const {    
    return ID;
}
string Reference::getTitle() const {
    return title;
}
string Reference::getAuthor() const{
    return author;
}
int Reference::getYear() const{
    return year_publication;
}

//setters
void Reference::setID(int a) {
    ID = a;
}
void Reference::setTitle(string a) {
    title = a;
}
void Reference::setAuthor(string a) {
    author = a;
}
void Reference::setYear(int a) {
    year_publication = a;
}

void Reference::print() {    
    cout << "ID: " << getID() << endl << "Title: " << getTitle() << endl;
    cout << "Author: " << getAuthor() << endl << "Year of publication: " << getYear() << endl;
}