#pragma once
#include <iostream>
#include <string>
#include "Reference.h"

using namespace std;

class ReferenceManager {
private:
	int Max;
	Reference** list_Reference;
	//Article* list_Article;
	//Book* list_Book;
	//TextBook* list_TextBook;
	int num_Reference;

public:
	ReferenceManager();
	ReferenceManager(int capacity);
	ReferenceManager(const ReferenceManager& a);
	~ReferenceManager();

	bool AddReference(Reference* r);
	int get(int pos);
	bool Delete(int pos);
	bool Search(int id);

	int getnum_Reference() const;

	virtual void print();

};
