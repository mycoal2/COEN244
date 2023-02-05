#pragma once
#include <iostream>
#include <string>
#include "Reference.h"

using namespace std;

class Article :public Reference {
private:
	string journal;
	int starPage;
	int endPage;

public:
	Article();
	Article(string title, string author, int year, string journal, int starpage, int endpage);
	Article(const Article& a);
	~Article();

	string getJournal() const;
	int getstarPage() const;
	int getendPage() const;
	int getNumberOfPages() const;

	void setJournal(string a);
	void setstarPage(int a);
	void setendPage(int a);

	virtual void print();
};
