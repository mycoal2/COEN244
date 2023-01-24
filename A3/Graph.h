#pragma once
#include <iostream>
#include <iomanip>
#include <string>

#include "Vertex.h"
#include "Edge.h"

class Graph {
public:
	Graph() {};
	virtual ~Graph() {};

	//add in one vertex; bool returns if it is added successfully.
	virtual bool addVertex(Vertex& v) = 0;
	virtual bool addVertices(Vertex* vArray, int N) = 0;
	//the edges that has connection with this vertex need to be removed;
	virtual bool removeVertex(Vertex& v) = 0;
	
	//remove a edge;  as a result, some node may remain as orphan.
	virtual bool addEdge(Edge& e) = 0;
	// remove the edge		
	virtual bool remove(Edge& e) = 0;
	// return bool if a vertex exists in a graph;
	
	virtual bool searchVertex(const Vertex& v) const = 0;
	// return bool if a Edge exists in a graph;
	virtual bool searchEdge(const Edge& e) const= 0;

	// display the whole graph with your own defined format
	virtual void display() const = 0;
	// convert the whole graph to a string such as 1‐2‐4‐5; 1‐3‐5; each path is separated by ';'
	virtual std::string toString() const = 0;
	//remove all the vertices and edges;
	virtual bool clean() = 0;


	// you may consider the following in your project:
	// add/remove a set of edge; as a result, some node may remain as orphan.
	// virtual bool addEdges(Edge* eArray) = 0;
	// virtual bool removeEdges(Edge* eArray) = 0; 
	//  
	// display the path that contains the vertex;
	// virtual void display(Vertex& v) const = 0;
	// display the path that contains the edge;
	// virtual void display(Edge& e) const = 0;

};