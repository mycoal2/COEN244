#pragma once
#include <iostream>
#include <iomanip>
#include <string>

class DirectedGraph;

class Edge {
public:
	Edge();
	Edge(int weight, int start, int end);
	~Edge();

	int getWeight() const;
	int getStart_Vertex() const;
	int getEnd_Vertex() const;

	void setWeight(int a);
private:
	int Weight;
	int Start_Vertex;
	int End_Vertex;
};

