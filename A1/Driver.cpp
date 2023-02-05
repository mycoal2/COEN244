#include <iostream>
#include <string>
#include "Date.h"
#include "information.h"
#include "Guest.h"
#include "Reservation_Manager.h"
#include "Guests_Res_Request.h"

using namespace std;

int main() {
	cout << "Welcome to Hotel C++ " << endl;

	Date B11(1, 5, 1991);		//info of group 1
	information G11("Gregory", "Felton", B11);				//Group1 Client 1
	Date B12(8, 15, 1991);
	information G12("Lee", "Victor", B12);					//Group1 Client 2
	Date B13(10, 21, 2002);
	information G13("William", "Hills", B13);				//Group1 Client 3

	Guest G1(1, 3);														//Group 1 staying from march 1 to march 3
	G1.addClient(G11);
	G1.addClient(G12);
	G1.addClient(G13);
	cout << "Information of all guest in Group 1" << endl;	
	G1.printGuest();		// Room number will be defaulted to 0 because it has not been requested yet in the reservation manager
	
	Guests_Res_Request R1(&G1);
	cout << "Reservation Request of Group 1" << endl;
	R1.printRequest();		//room number still 0

	Date B21(4, 9, 1995);	//info of group 2
	information G21("Billy", "Davis", B21);				//Group2 Client 1
	Date B22(10, 26, 1994);
	information G22("Roy", "Hernade", B22);				//Group2 Client 2
	
	Guest G2(3, 7);														//Group 2 staying from march 3 to march 7
	G2.addClient(G21);
	G2.addClient(G22);
	//G2.printGuest();		This will show information of Group 2
	Guests_Res_Request R2(&G2);
	//cout << "Reservation Request of Group 2" << endl;
	//R2.printRequest();				
	

	Reservation_Manager Manager(&R1);	//calling parameterized constructor with Request from group 1
	//Manager.printSchedule();		//schedule with only group 1

	Manager.book(&R2);				//adding Group 2 to the schedule

	/*	Test for debugging
	cout << "Information of Group with ID 2" << endl;
	Manager.printReservation(2);			//2 = R2.getID()

	cout << "Information of Group with ID 1" << endl;
	Manager.printReservation(1);	//1 = R1.getID()
	*/

	//cout << endl << "Schedule of available rooms" << endl;
	//Manager.printSchedule();		//schedule with group 1 and 2
	
	Date B31(10, 8, 2002);
	information G31("Robert", "Dacus", B31);		//Group3 Client 1

	Guest G3(2, 6);														//Group 3 staying from march 2 to march 6
	G3.addClient(G31);
	Guests_Res_Request R3(&G3);
	Manager.book(&R3);
	//cout << "ID of Group 3: " << R3.getID() << endl;			//To check unique ID
	//Manager.printSchedule();		//schedule with group 1 and 2 and 3
	

	Date B41(7, 14, 1993);	//info of group 2
	information G41("Gary", "Rodis", B21);			//Group4 Client 1

	Guest G4(2, 3);														//Group 4 staying from march 2 to march 3
	G4.addClient(G41);
	Guests_Res_Request R4(&G4);
	Manager.book(&R4);

	Date B51(9, 2, 2001);
	information G51("Jeremy", "Collins", B51);		//Group5 Client 1

	Guest G5(5, 5);														//Group 5 only staying 1 night on march 5
	G5.addClient(G51);
	Guests_Res_Request R5(&G5);
	Manager.book(&R5);

	Date B61(6, 12, 1989);
	information G61("Bob", "Bloss", B61);		//Group6 Client 1

	Guest G6(1, 7);														//Group 6 staying from march 1 to march 7
	G6.addClient(G61);
	Guests_Res_Request R6(&G6);
	Manager.book(&R6);

	cout << endl << "Schedule of available rooms" << endl;
	Manager.printSchedule();
	cout << endl << "Number of Request: " << Manager.getnum_request() << endl;					//number of requests before cancel
	Manager.cancel(3);			//3 is group 3 which is from march 2 to march 6
	cout << endl << "Number of Request after cancel: " << Manager.getnum_request() << endl;		//number of requests after cancel
	cout << endl << "New Schedule after cancellation" << endl;
	Manager.printSchedule();
	cout << endl;
	Manager.printReservation();		//info of all reservations
	Manager.printReservation(3);	//info of ID 3, but it does not exist because it has been cancelled
	Manager.printReservation(5);	//info of ID 5


	/*
	Random name and date of birth generated online
	Group 1:	1-3
		Gregory Felton
		1/5/1991
		Lee Victor
		8/15/1991
		William Hills
		10/21/2002

	Group 2:	3-7
		Billy Davis
		4/9/1995
		Roy Hernade
		10/26/1994

	Group 3:	2-6
		Robert Dacus
		10/8/2002

	Group 4:	2-3
		Gary Rodis
		7/14/1993

	Group 5:	5
		Jeremy Collins
		9/2/2001

	*/




	return 0;
}