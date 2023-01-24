#include <iostream>
#include <string>
#include <vector>
#include "1TA.h"

using namespace std;

TA1::TA1() {
	Status = "";
	Dept = "";
	Name = "";
	Age = 0;
	StudentID = 0;
}

bool TA1::checkAlum() {
	if (Status == "Alum") {
		return true;
	}
	else {
		return false;
	}
}

int TA1::getAge() {
	return Age;
}
void TA1::setStatus(string s) {
	Status = s;
}
void TA1::setDept(string d) {
	Dept = d;
}
void TA1::setName(string n) {
	Name = n;
}
void TA1::setAge(int a) {
	Age = a;
}
void TA1::setStudentID(int id) {
	StudentID = id;
}
void TA1::print() {
	cout << Status << "     " << Dept << "     " << Name << "     " << Age << "     " << StudentID;
}

string TA1::writing() {
	string line;
	line = (Status + "     " + Dept + "     " + Name + "     " + to_string(Age) + "     " + to_string(StudentID));
	return line;
}
