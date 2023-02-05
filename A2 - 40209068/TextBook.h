#pragma once
#include <iostream>
#include <string>
#include "Reference.h"
#include "Book.h"

using namespace std;

class TextBook : public Book {
private:
	string Web_Url;

public:
	TextBook();
	TextBook(string title, string author, int year, string publisher, int NumberOfPage, string web);
	TextBook(const TextBook& a);
	~TextBook();

	string getWeb_Url() const;
	void setWeb_Url(string a);
	virtual void print();
};

