#include <iostream>
#include <string>
#include "Guest.h"

using namespace std;


Guest::Guest() {
	Checkin = new Date();
	Checkout = new Date();
	Clients = new information[max];
	Checkin->setDay(0);
	Checkout->setDay(0);
	numClients = 1;
	RoomNum = 0;						//need to check availlable rooms first
}
Guest::Guest(int in, int out) {
	Checkin = new Date(3, in, 2022);
	Checkout = new Date(3, out, 2022);
	Clients = new information[max];
	numClients = 0;
	RoomNum = 0;						//need to check availlable rooms first
}
Guest::Guest(const Guest &copy) {
	Checkin = new Date(*copy.getCheckIn());
	Checkout = new Date(*copy.getCheckOut());
	Clients = new information[max];
	numClients = copy.getnumClients();
	Clients = copy.Clients;
	RoomNum = copy.RoomNum;
}

Date* Guest::getCheckIn() const {
	return Checkin;
}
Date* Guest::getCheckOut() const {
	return Checkout;
}

int Guest::getRoomNum() const {
	return RoomNum;
}
int Guest::getnumClients() const {
	return numClients;
}
information* Guest::getGuest() const {
	return Clients;
}

void Guest::addClient(const information& a) {
	if (numClients < 4) {
		Clients[numClients] = a;
		numClients++;
	}
	else {
		cout << "Can not share the same room. Not enough room" << endl;
	}
}

void Guest::setCheckIn(int day) {
	Checkin->setDay(day);
}
void Guest::setCheckOut(int day) {
	Checkout->setDay(day);
}
void Guest::setRoomNum(int room) {
	RoomNum = room;
}

void Guest::printGuest() {
	cout << "Check in date: ";
	getCheckIn()->printDate();
	cout << "Check out date: ";
	getCheckOut()->printDate();
	cout << "Room number: " << getRoomNum() << endl;
	cout << "There is " << getnumClients() << " Clients in this room" << endl;;
	for (int i = 0; i < numClients; i++) {
		Clients[i].printInfo();
		cout << endl;
		//cout << "Clients: " << Clients[0].getfName() << Clients[0].getlName();
	}
	
}

Guest::~Guest() {
	//delete Checkin;
	//delete Checkout;
	//delete[] Clients;
}