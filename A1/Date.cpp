#include <iostream>
#include <string>
#include "Date.h"


using namespace std;

	Date::Date() {
		Month = 0;
		Day = 0;
		Year = 0;
	}
	Date::Date(int month, int day, int year) {
		Month = month;
		Day = day;
		Year = year;
	}
	Date::Date(const Date &copy) {
		Month = copy.getMonth();
		Day = copy.getDay();
		Year = copy.getYear();
	}

	int Date::getMonth() const{
		return Month;
	}
	int Date::getDay() const{
		return Day;
	}
	int Date::getYear() const {
		return Year;
	}

	void Date::setMonth(int month) {
		Month = month;
	}
	void Date::setDay(int day) {
		Day = day;
	}
	void Date::setYear(int year) {
		Year = year;
	}

	void Date::printDate() {
		cout << getMonth() << "/" << getDay() << "/" << getYear() << endl;
	}
