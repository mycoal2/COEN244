#pragma once
#include <iostream>
#include <iomanip>
#include <string>

class DirectedGraph;

class Vertex {
public:
	Vertex();
	Vertex(std::string value);
	~Vertex();

	int getID() const;
	int getID_Counter() const;
	std::string getValue() const;

	void setValue(std::string a);

private:
	int ID;
	static int ID_Counter;
	std::string Value;
	//Edge* connections;

};

