#pragma once
#include <iostream>
#include <string>
#include "Reference.h"

using namespace std;

class Book : public Reference {
private:
	string publisher;
	int NumberOfPage;

public:
	Book();
	Book(string title, string author, int year, string publisher, int NumberOfPage);
	Book(const Book& a);
	~Book();


	string getPublisher() const;
	int getNumberOfPage() const;

	void setPublisher(string a);
	void setNumberOfPage(int a);

	virtual void print();

};
