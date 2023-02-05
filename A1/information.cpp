#include <iostream>
#include <cstring>
#include <string>
#include "information.h"

using namespace std;

information::information() {
	firstName = new char;
	firstName = nullptr;
	lastName = new char;
	lastName = nullptr;
	Birth = new Date;
}
information::information(const char* fname, const char* lname, Date birth) {
	firstName = new char[strlen(fname) + 10];
	lastName = new char[strlen(lname) + 10];
	strcpy_s(firstName, sizeof(fname)+1, fname);
	strcpy_s(lastName, sizeof(lname)+1, lname);
	Birth = new Date(birth);
}
information::information(const information& info) {
	firstName = new char[strlen(info.getfName()) + 1];
	lastName = new char[strlen(info.getfName()) + 1];
	strcpy_s(firstName, sizeof(info.getfName())+1, info.getfName());
	strcpy_s(lastName, sizeof(info.getfName())+1, info.getfName());
	Birth = new Date(*info.getbirth());
}

char* information::getfName() const {
	return firstName;
}
char* information::getlName() const {
	return lastName;
}
Date* information::getbirth() const {
	return Birth;
}

void information::setInfo(char* fname, char* lname) {
	firstName = fname;
	lastName = lname;
}
void information::setInfo(char* fname, char* lname, int month, int day, int year) {
	firstName = fname;
	lastName = lname;
	Birth->setMonth(month);
	Birth->setDay(day);
	Birth->setYear(year);
}

void information::setfName(char* fname) {
	firstName = fname;
}
void information::setlName(char* lname) {
	lastName = lname;
}
void information::setbirth(Date *birth) {
	Birth = birth;
}
void information::setbirth(int month, int day, int year) {
	Birth->setMonth(month);
	Birth->setDay(day);
	Birth->setYear(year);
}

void information::printInfo() {
	cout << "First Name: " << getfName() << endl << "Last Name: " << getlName() << endl;
	cout << "Date of birth: ";
	Birth->printDate();
}

information::~information() {
//	delete[] firstName;		breaks my code - I do not know how to fix / delete on the heap
//	delete[] lastName;
//	delete Birth;
//
}