#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Date.h"
#include "information.h"
#include "Guest.h"

using namespace std;

class Guests_Res_Request {
	public:

		Guests_Res_Request();							//default 
		Guests_Res_Request(Guest* client);
		Guests_Res_Request(Guests_Res_Request &copy);	//copy 

		~Guests_Res_Request();							//destructor

		void setnights();

		Guest* getgroup() const;
		int getnights() const;
		int getID() const;

		void printRequest();

	private:
		Guest* group;
		int ID;
		static int IDcounter;
		int nights;
};