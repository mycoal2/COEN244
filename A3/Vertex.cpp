#pragma once
#include <iostream>
#include <iomanip>
#include <string>

#include "Vertex.h"

using namespace std;

int Vertex::ID_Counter = 1;
Vertex::Vertex() {
	ID = ID_Counter;
	ID_Counter++;
	Value = "?";
	//connections = new Edge[10];
}
Vertex::Vertex(string value) {
	Value = value;
	ID = ID_Counter;
	ID_Counter++;
	//connections = new Edge[10];
}
Vertex::~Vertex() {
//	delete[] connections;
}

int Vertex::getID() const {
	return ID;
}
int Vertex::getID_Counter() const {
	return ID_Counter;
}
string Vertex::getValue() const {
	return Value;
}

void Vertex::setValue(string a) {
	Value = a;
}