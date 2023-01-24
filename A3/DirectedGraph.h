#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

#include "Graph.h"
#include "Vertex.h"
#include "Edge.h"


using namespace std;

class DirectedGraph : public Graph {
private:
	int NumOfVertex;
	int NumOfEdge;
	int MaxNumVertex;
	Vertex* Vertices;
	Edge* Edges;

public:
	DirectedGraph();
	DirectedGraph(Vertex&);						//constructor to add 1 vertex
	DirectedGraph(Vertex* V, int Numberadded);	//constructor to add an array of vertex
	DirectedGraph(const DirectedGraph& Copy); 	//copy constructor
	~DirectedGraph();


	bool EdgeExists(const Edge& e);
	int getNumVertex() const;
	int getNumEdge() const;
	Vertex* getVertexArray() const;
	Edge* getEdgeArray() const;

	virtual bool addVertex(Vertex& v);					//add 1 vertex
	virtual bool addVertices(Vertex* vArray, int N);	//add multiple vertices
	virtual bool removeVertex(Vertex& v);				//remove 1 vertex along with its edges
	
	virtual bool addEdge(Edge& e);						//add 1 edge
	virtual bool remove(Edge& e);						//remove 1 edge
	
	virtual bool searchVertex(const Vertex& v) const;			//search if vertex exists
	virtual bool searchEdge(const Edge& e) const;				//search if edge exists

	virtual void display() const;								//print graph
	// convert the whole graph to a string such as 1‐2‐4‐5; 1‐3‐5; each path is separated by ';'
	// or just print the edges of the graph as a list
	// define your own format of a string representation of the graph.
	virtual string toString() const;

	virtual bool clean();								//remove all vertices and edge			
	
	bool operator==(const DirectedGraph& g) const;
	DirectedGraph& operator+(const DirectedGraph& g);
	DirectedGraph& operator=(const DirectedGraph& g);
	DirectedGraph& operator++();						//  ++object
	DirectedGraph& operator++(int);						//	object++
	bool operator>(const DirectedGraph& g) const;
	friend ostream& operator<<(ostream& output, const DirectedGraph& g);


};

