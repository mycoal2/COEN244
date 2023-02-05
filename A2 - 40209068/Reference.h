#pragma once
#include <iostream>
#include <string>
#include "Reference.h"

using namespace std;

class Reference {
private:
	int ID;
	static int uniqueID;
	string title;
	string author;
	int year_publication;

public:
	Reference();
	Reference(string title, string author, int year);
	Reference(const Reference& ref);
	~Reference();

	int getID() const;
	string getTitle() const;
	string getAuthor() const;
	int getYear() const;

	void setID(int a);
	void setTitle(string a);
	void setAuthor(string a);
	void setYear(int a);

	virtual void print();

};

