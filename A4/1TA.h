#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class TA1 {
	public:
		TA1();
		TA1(string status, string dept, string name, int age, int studentid);	

		bool checkAlum();
		string writing();
		void setStatus(string s);
		void setDept(string d);
		void setName(string n);
		void setAge(int a);
		void setStudentID(int id);

		int getAge();

		void print();

	private:
		string Status;
		string Dept;
		string Name;
		int Age;
		int StudentID;



};