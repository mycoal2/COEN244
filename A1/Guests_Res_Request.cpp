#include <iostream>
#include <string>
#include "Guests_Res_Request.h"

using namespace std;

int Guests_Res_Request::IDcounter = 0;

Guests_Res_Request::Guests_Res_Request() {
	group = new Guest;
	ID = IDcounter;
	nights = 0;
}	
Guests_Res_Request::Guests_Res_Request(Guest* client) {
	group = client;
	IDcounter++;
	ID = IDcounter;
	nights = client->getCheckOut()->getDay() - client->getCheckIn()->getDay() + 1;		// 3 - 1 = 2. day1 day2 day3
}

Guests_Res_Request::Guests_Res_Request(Guests_Res_Request& copy) {
	group = copy.group;
	IDcounter = copy.IDcounter;
	ID = copy.getID();
	nights = copy.getnights();
}

Guests_Res_Request::~Guests_Res_Request() {
//	delete group;
}

void Guests_Res_Request::setnights() {
	nights = group->getCheckOut()->getDay() - group->getCheckIn()->getDay() + 1;
}

Guest* Guests_Res_Request::getgroup() const {
	return group;
}
int Guests_Res_Request::getnights() const {
	return nights;
}
int Guests_Res_Request::getID() const {
	return ID;
}

void Guests_Res_Request::printRequest() {
	cout << "ID: " << getID() << endl;
	cout << "Staying for " << getnights() << " nights." << endl;
	group->printGuest();
	cout << endl;
}