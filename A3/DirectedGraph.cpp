#include <iostream>
#include <iomanip>
#include <string>

#include "DirectedGraph.h"

using namespace std;


DirectedGraph::DirectedGraph() {
	MaxNumVertex = 20;
	NumOfVertex = 0;
	NumOfEdge = 0;
	Vertices = new Vertex[MaxNumVertex];
	Edges = new Edge[MaxNumVertex];
}
DirectedGraph::DirectedGraph(Vertex& V) {
	MaxNumVertex = 20;
	NumOfVertex = 0;
	NumOfEdge = 0;
	Vertices = new Vertex[MaxNumVertex];
	Vertices[0] = V;
	NumOfVertex++;
	Edges = new Edge[MaxNumVertex];
}
DirectedGraph::DirectedGraph(Vertex* V, int Numberadded) {
	MaxNumVertex = 20;
	NumOfVertex = 0;
	NumOfEdge = 0;
	Vertices = new Vertex[MaxNumVertex];
	for (int i = 0; i < Numberadded; i++) {
		Vertices[i] = V[i];
		NumOfVertex++;
	}
	Edges = new Edge[MaxNumVertex];
}
DirectedGraph::DirectedGraph(const DirectedGraph& copy) {
	MaxNumVertex = copy.MaxNumVertex;
	NumOfVertex = copy.NumOfVertex;
	NumOfEdge = copy.NumOfEdge;
	Vertices = new Vertex[MaxNumVertex];
	Edges = new Edge[MaxNumVertex];
	Vertices = copy.Vertices;
	Edges = copy.Edges;
}

DirectedGraph::~DirectedGraph() {
	delete[] Vertices;
	delete[] Edges;
}

int DirectedGraph::getNumVertex() const {
	return NumOfVertex;
}
int DirectedGraph::getNumEdge() const {
	return NumOfEdge;
}
Vertex* DirectedGraph::getVertexArray() const {
	return Vertices;
}
Edge* DirectedGraph::getEdgeArray() const {
	return Edges;
}


bool DirectedGraph::addVertex(Vertex& v) {
	if (NumOfVertex < 20) {			//check if maximum of vertex is reached
		Vertices[NumOfVertex] = v;
		NumOfVertex++;
		return true;
	}
	else {
		return false;
	}
}

bool DirectedGraph::addVertices(Vertex* vArray, int N) {
	if (NumOfVertex + N <= 20) {	//check if maximum of vertex is reached after adding all vertex
		for (int i = 0; i < N; i++) {
			Vertices[NumOfVertex] = vArray[i];
			NumOfVertex++;
		}
		return true;
	}
	else {
		return false;
	}
}

bool DirectedGraph::removeVertex(Vertex& v) {
	for (int i = 0; i < NumOfVertex; i++) {
		if (Vertices[i].getID() == v.getID()) {
			for (int j = i; j < NumOfVertex-1; j++) {
				Vertices[j] = Vertices[j + 1];
			}
			NumOfVertex--;
			return true;
		}
	} 
	return false;
}

bool DirectedGraph::addEdge(Edge& e) {
	for (int i = 0; i < NumOfVertex; i++) {
		if (e.getStart_Vertex() == Vertices[i].getID()) {
			for (int j = 0; j < NumOfVertex; j++) {
				if (e.getEnd_Vertex() == Vertices[j].getID()) {
					if (EdgeExists(e)) {
						cout << "Edge exists --- ";
						return false;
					}
					else {
						Edges[NumOfEdge] = e;
						NumOfEdge++;
						return true;
					}
				}
				else {
					if (j == NumOfVertex - 1) {
						cout << "End vertex does not exists --- ";
						return false;
					}
				}
			}
		}
		else {
			if (i == NumOfVertex - 1) {
				cout << "Start vertex does not exists --- ";
				return false;
			}
		}
	}
	return false;
}

bool DirectedGraph::EdgeExists(const Edge& e) {
	for (int i = 0; i < NumOfEdge; i++) {
		if (Edges[i].getStart_Vertex() == e.getStart_Vertex() && Edges[i].getEnd_Vertex() == e.getEnd_Vertex()) {
			return true;
		}
	}
	return false;
}

bool DirectedGraph::remove(Edge& e) {
	if (EdgeExists(e)) {
		for (int i = 0; i < NumOfEdge; i++) {
			if (Edges[i].getStart_Vertex() == e.getStart_Vertex() && Edges[i].getEnd_Vertex() == e.getEnd_Vertex()) {
				for (int j = i; j < NumOfEdge - 1; j++) {
					Edges[j] = Edges[j + 1];
				}
				NumOfEdge--;
				return true;
			}
		}
	}
	return false;
}

bool DirectedGraph::searchVertex(const Vertex& v) const {
	for (int i = 0; i < NumOfVertex; i++) {
		if (Vertices[i].getID() == v.getID() && Vertices[i].getValue() == v.getValue()) {
			return true;
		}
	}
	return false;
}


bool DirectedGraph::searchEdge(const Edge& e) const {
	for (int i = 0; i < NumOfEdge; i++) {
		if (Edges[i].getStart_Vertex() == e.getStart_Vertex() && Edges[i].getEnd_Vertex() == e.getEnd_Vertex() && Edges[i].getWeight() == e.getWeight()) {
			return true;
		}
	}
	return false;
}	

void DirectedGraph::display() const {
	cout << "List of Vertex:" << endl;
	for(int i = 0; i < NumOfVertex; i++) {
		cout << Vertices[i].getID() << " = " << Vertices[i].getValue() << endl;
	}
	cout << "List of edges:" << endl;
	for(int i = 0; i < NumOfEdge; i++) {
		if(Edges[i].getWeight() != -1) {
			cout << Edges[i].getStart_Vertex() << " --" << Edges[i].getWeight() << "km--> " << Edges[i].getEnd_Vertex();
			cout << "               ";
			if(i+1 % 3 == 0) {
				cout << endl;
			}
		}
	}
	cout << endl;
}

string DirectedGraph::toString() const {
	string Sgraph = "";
	string hold;
	for(int i = 0; i < NumOfEdge; i++) {
		hold = to_string(Edges[i].getStart_Vertex()) + " --" + to_string(Edges[i].getWeight()) + "km --> " + to_string(Edges[i].getEnd_Vertex());
		hold = hold + "    ";
		Sgraph = Sgraph + hold;
	}
	return Sgraph;
}

bool DirectedGraph::clean() {
	delete[] Vertices;
	delete[] Edges;
	Vertices = new Vertex[MaxNumVertex];
	NumOfVertex = 0;
	Edges = new Edge[MaxNumVertex];
	NumOfEdge = 0;
	return true;
}
bool DirectedGraph::operator==(const DirectedGraph& g) const {
	if(NumOfEdge != g.NumOfEdge && NumOfVertex != g.NumOfVertex) {
		return false;
	}
	for (int i = 0; i < NumOfVertex; i++) {
		if(!g.searchVertex(Vertices[i])) {
			return false;
		}
	}
	for (int i = 0; i < NumOfEdge; i++) {
		if(!g.searchEdge(Edges[i])) {
			return false;
		}
	}
	return true;
}	

DirectedGraph& DirectedGraph::operator=(const DirectedGraph& g) {
	if (*this == g) {
		return *this;			//check if it is the same graph
	}
	else {
		NumOfVertex = g.NumOfVertex;
		NumOfEdge = g.NumOfEdge;
		delete[] Vertices;
		delete[] Edges;
		Vertices = new Vertex[MaxNumVertex];
		Edges = new Edge[MaxNumVertex];
		for (int i = 0; i < NumOfVertex; i++) {
			Vertices[i] = g.Vertices[i];
		}
		for (int i = 0; i < NumOfEdge; i++) {
			Edges[i] = g.Edges[i];
		}

	}
	return *this;
}

DirectedGraph& DirectedGraph::operator+(const DirectedGraph& g1) {
	DirectedGraph* temp = new DirectedGraph;
	temp->addVertices(g1.getVertexArray(), g1.getNumVertex());
	temp->addVertices(getVertexArray(), getNumVertex());

	for (int i = 0; i < g1.getNumEdge(); i++) {				//did not code function to add an array of edges
		temp->addEdge(g1.getEdgeArray()[i]);
	}
	for (int i = 0; i < getNumEdge(); i++) {				//did not code function to add an array of edges
		temp->addEdge(getEdgeArray()[i]);
	}
	return *temp;

}



DirectedGraph& DirectedGraph::operator++() {
	if (NumOfEdge == 0) {
		cout << "No edges to increment" << endl;
		return *this;
	}
	for(int i = 0; i < NumOfEdge; i++) {
		Edges[i].setWeight(Edges[i].getWeight()+1);
		
	}
	return *this;
}
DirectedGraph& DirectedGraph::operator++(int a) {
	if (NumOfEdge == 0) {
		cout << "No edges to increment" << endl;
		return *this;
	}
	for (int i = 0; i < NumOfEdge; i++) {
		Edges[i].setWeight(Edges[i].getWeight() + 1);
	}
	return *this;
}

bool DirectedGraph::operator>(const DirectedGraph& g) const {
	int temp1 = 0;
	int temp2 = 0;
	for(int i = 0; i < NumOfEdge; i++) {	// sum of first graph
		temp1 = temp1 + this->Edges[i].getWeight();
	}
	for(int i = 0; i < g.getNumEdge(); i++) {	// sum of second grapj
		temp2 = temp2 + g.getEdgeArray()[i].getWeight();
	}
	return(temp1>temp2);
}

ostream& operator<<(ostream& output, const DirectedGraph& g) {
	for (int i = 0; i < g.getNumVertex(); i++) {
		output << g.getVertexArray()[i].getID() << " = " << g.getVertexArray()[i].getValue() << endl;
	}
	output << g.toString() << endl;
	return output;
}
