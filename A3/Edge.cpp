#pragma once
#include <iostream>
#include <iomanip>
#include <string>

#include "Edge.h"

using namespace std;

Edge::Edge() {
	Weight = 0;
	Start_Vertex = -1;
	End_Vertex = -1;

}
Edge::Edge(int weight, int start, int end) {
	Weight = weight;
	Start_Vertex = start;
	End_Vertex = end;
}
Edge::~Edge() {

}

int Edge::getWeight() const {
	return Weight;
}
int Edge::getStart_Vertex() const {
	return Start_Vertex;
}
int Edge::getEnd_Vertex() const {
	return End_Vertex;
}

void Edge::setWeight(int a) {
	Weight = a;
}