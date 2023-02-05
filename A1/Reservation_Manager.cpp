#include <iostream>
#include <string>
#include <iomanip>
#include "Date.h"
#include "information.h"
#include "Guest.h"
#include "Guests_Res_Request.h"
#include "Reservation_Manager.h"

using namespace std;

Reservation_Manager::Reservation_Manager() {
	schedule = new int*[max_no_of_night];
	for (int i = 0; i < max_no_of_night; i++) {
		schedule[i] = new int[max_no_of_rooms];
		for (int j = 0; j < max_no_of_rooms; j++) {
			schedule[i][j] = 0;
		}
	}
	list = new Guests_Res_Request[100];
	num_request = 0;
	roomID = 0;
}
Reservation_Manager::Reservation_Manager(Guests_Res_Request* grouprequest) {
	schedule = new int* [max_no_of_night];
	for (int i = 0; i < max_no_of_night; i++) {
		schedule[i] = new int[max_no_of_rooms];
		for (int j = 0; j < max_no_of_rooms; j++) {
			schedule[i][j] = 0;
		}
	}
	list = new Guests_Res_Request[100];
	list[num_request] = *grouprequest;
	num_request++;
	roomID = 0;

	for (int i = 0; i < 20; i++) {								//check room available to give room ID
		if ((schedule[grouprequest->getgroup()->getCheckIn()->getDay()][i] == 0) &&
			(schedule[grouprequest->getgroup()->getCheckOut()->getDay()][i] == 0)) {
			roomID = i;
			grouprequest->getgroup()->setRoomNum(roomID+1);
			roomFree--;
			break;
		}
	}

	grouprequest->getgroup()->getCheckIn()->getDay();
	for (int i = grouprequest->getgroup()->getCheckIn()->getDay(); i <= grouprequest->getgroup()->getCheckOut()->getDay(); i++) {
		schedule[i - 1][grouprequest->getgroup()->getRoomNum()-1] = grouprequest->getID();			//this will change the 0 to their ID in the schedule
	}

}

void Reservation_Manager::book(const Guests_Res_Request* grouprequest) {
	list[num_request] = *grouprequest;
	num_request++;
	roomID = -1;
	for (int i = 0; i < 20; i++) {					//check which rooms are available for the whole stay
		if (checkFreeRooom(grouprequest->getgroup()->getCheckIn()->getDay(), grouprequest->getgroup()->getCheckOut()->getDay(), i)) {
			roomID = i;
			grouprequest->getgroup()->setRoomNum(roomID+1);
			roomFree--;
			break;
		}
	}
	if (roomID == -1) {

	}
	for (int i = grouprequest->getgroup()->getCheckIn()->getDay(); i <= grouprequest->getgroup()->getCheckOut()->getDay(); i++) {
		schedule[i - 1][grouprequest->getgroup()->getRoomNum()-1] = grouprequest->getID();			//this will change the 0 to their ID in the schedule
	}

}
void Reservation_Manager::cancel(int ID) {
	for (int i = 0; i < num_request; i++) {
		if (list[i].getID() == ID) {
			for (int j = list[i].getgroup()->getCheckIn()->getDay(); j <= list[i].getgroup()->getCheckOut()->getDay(); j++) {
				schedule[j - 1][list[i].getgroup()->getRoomNum()-1] = 0;		//this will change their ID back to 0 in the schedule
			}
			for (int j = i; j < num_request; j++) {				//shifts the elements of the array 
				list[j] = list[j + 1];
			}
			num_request--;
			//delete list[i].getgroup();			breaks my code - I do not know how to fix
			return;
		}
	}
	cout << "No reservation matches with the ID" << endl;
}

bool Reservation_Manager::checkFreeRooom(int in, int out, int room) {
	bool free = true;
		for (int i = in; i <= out; i++) {
			if (schedule[i-1][room] == 0) {
				free = true;
			}
			else {
				return false;
			}
		}
		
	return free;
}
int Reservation_Manager::getroomID() {
	return roomID;
}
int Reservation_Manager::getnum_request() {
	return num_request;
}
void Reservation_Manager::printReservation() {
	for (int i = 0; i < num_request; i++) {
		cout << "Information of " << i + 1 << endl;
		list[i].printRequest();
	}
	if (num_request == 0) {
		cout << "No reservation in the system" << endl;
	}
}
void Reservation_Manager::printReservation(int ID) {
	cout << "Information of " << ID << endl;
	for (int i = 0; i < num_request; i++) {
		if (list[i].getID() == ID) {
			list[i].printRequest();
			return;
		}
	}
	cout << "No reservation matches with the ID" << endl;
}
void Reservation_Manager::printSchedule() {
	cout << "      ";						// space for date
	for (int i = 0; i < max_no_of_rooms; i++) {
		cout << setw(6) << i + 1;			//room numbering
	}
	cout << endl << "______________________________________________________________";
	cout << "__________________________________________________________________\n" << endl;	//formatting

	for (int i = 0; i < max_no_of_night; i++) {				//print schedule
		cout << setw(5) << "Mar" << i + 1;
		for (int j = 0; j < max_no_of_rooms; j++) {
			cout << setw(6) << schedule[i][j];
		}
		cout << endl;
	}

	
}

Reservation_Manager::~Reservation_Manager() {
	//delete list;
	//for (int i = 0; i < max_no_of_night; i++) {
	//	delete schedule[i];
	//}
	//delete schedule;
}
	