#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include "Date.h"

using namespace std;

class information {
	public:

		information();							//default
		information(const char* firstName, const char* lastName, Date birth);
		information(const information &info);	//copy

		char* getfName() const;
		char* getlName() const;
		Date* getbirth() const;

		void setInfo(char* firstName, char* lastName);
		void setInfo(char* fname, char* lname, int month, int day, int year);

		void setfName(char* firstName);
		void setlName(char* lastName);
		void setbirth(Date* birth);
		void setbirth(int month, int day, int year);

		void printInfo();

		~information();		//destructor

	private:
		char* firstName;	//string firstName;
		char* lastName;		//string lastName;
		Date* Birth;
};