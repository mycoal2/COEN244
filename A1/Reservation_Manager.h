#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Date.h"
#include "information.h"
#include "Guest.h"
#include "Guests_Res_Request.h"

using namespace std;

class Reservation_Manager {
	public:
		Reservation_Manager();
		Reservation_Manager(Guests_Res_Request* group);

		void book(const Guests_Res_Request* group);
		void cancel(int ID);

		int getroomID();
		int getnum_request();
		bool checkFreeRooom(int in, int out, int room);

		void printReservation();			//info of all reservations
		void printReservation(int ID);
		void printSchedule();

		~Reservation_Manager();

	private:
		const int max_no_of_night = 7;
		const int max_no_of_rooms = 20;
		int roomID;
		int roomFree = 20;;
		Guests_Res_Request* list;
		int** schedule;
		int num_request;
};