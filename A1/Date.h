#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Date {
	public:
		Date();						//default constructor
		Date(int month, int day, int year);
		Date(const Date&);			//copy constructor

		int getMonth() const;				
		int getDay() const;
		int getYear() const;

		void setMonth(int month);			
		void setDay(int day);
		void setYear(int year);

		void printDate();

	private:
		int Month;
		int Day;
		int Year;
};