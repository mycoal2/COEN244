#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include "1TA.h"

using namespace std;

int main() {
	vector<string> File;
	vector<TA1> TA;
	ifstream inFile;	
	inFile.open("TAList.txt");						//name of txtfile TAList.txt
	if (!inFile) {
		cout << "File could not be opened" << endl;
		return 0;
	}
	else {
		string line;
		while (getline(inFile, line)) {				
			File.push_back(line);
		}
		File.erase(File.begin());					//erasing the first line which is the number of TA
	}
	inFile.close();


	for (int i = 0; i < File.size(); i++) {
		TA1* ta = new TA1;
		stringstream ss(File[i]);					//separating the words
		string s;
		int num;
		ss >> s;									
		ta->setStatus(s);
		ss >> s;
		ta->setDept(s);
		ss >> s;
		ta->setName(s);
		ss >> num;
		ta->setAge(num);
		ss >> num;
		ta->setStudentID(num);						//setting all data members of object
		TA.push_back(*ta);							//inserting object into vector
		}
	for (int i = 0; i < TA.size(); i++) {
//		TA[i].print();						test to check what is read from file before deleting
//		cout << endl;

		if (TA[i].checkAlum()) {				//If alum, objects gets deleted
			TA.erase(TA.begin() + i);
			i = i - 1;							//index gets shifted after deleting
		}
	}
	
	
	/*
	string s = "Alum";								// this is without objects
	for (int i = 0; i < TA.size(); i++) {
		stringstream ss(TA[i]);
		string num;
		while (ss >> num) {							//It only checks first word and if its "Alum"
			if (num == s) {							//the string in the vector gets deleted
				TA.erase(TA.begin() + i);
				i = i - 1;							//The index gets shifted when the string gets deleted
			}
			else {
				break;
			}
		}
	}
	*/

	ofstream newFile;
	newFile.open("TAList.txt");									//name of txtfile TAList.txt
	if (!newFile) {
		cout << "File could not be opened" << endl;
	}
	else {
		newFile << TA.size() << endl;
		for (int i = 0; i < TA.size(); i++) {
			newFile << TA[i].writing() << endl;					//writing to file
		}
	}
	

	return 0;
}