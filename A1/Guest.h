#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Date.h"
#include "information.h"

using namespace std;

class Guest {
	public:

		Guest();					//default
		Guest(int in, int out);		//Check in date and Check out date
		Guest(const Guest &);		//copy

		Date* getCheckIn() const;
		Date* getCheckOut() const;

		int getRoomNum() const;
		int getnumClients() const;
		information* getGuest() const;

		void addClient(const information& a);

		void setCheckIn(int a);
		void setCheckOut(int a);
		void setRoomNum(int room);				//need to check availlable rooms first

		void printGuest();

		~Guest(); //destructor

	private:
		int numClients;							//number of clients
		const int max = 4;
		Date* Checkin;							// 1 to 7
		Date* Checkout;
		information* Clients;
		int RoomNum;

};