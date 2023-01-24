#include <iostream>
#include <iomanip>
#include <string>

#include "Graph.h"
#include "DirectedGraph.h"
#include "Edge.h"
#include "Vertex.h"


using namespace std;

int main() {
	Vertex Node1("Josh");					// ID 1
	Vertex* ArrayVertex = new Vertex[3];	// Generates ID 2,3,4 for each the respective index
	ArrayVertex[0].setValue("John");		// ID 2
	ArrayVertex[1].setValue("Ball");		// ID 3
	ArrayVertex[2].setValue("Ron");			// ID 4
	Vertex Node5("Bob");					// ID 5
	Vertex Node6("Mod");					// ID 6

	Edge Edge1(5, 1, 3); 	//Edge from 1 to 3 with a weight of 5.
	Edge Edge2(14, 1, 5); 	//Edge from 1 to 5 with a weight of 14.
	Edge Edge3(9, 3, 2); 	//Edge from 3 to 2 with a weight of 9.
	Edge Edge4(2, 5, 4); 	//Edge from 5 to 4 with a weight of 2.
	Edge Edge5(19, 6, 2);	//Edge from 6 to 2 with a weight of 19.
	Edge Edge6(6, 2, 4);
	Edge Edge7(11, 5, 6);
	DirectedGraph Graph1(Node1);

	if (Graph1.addVertex(Node5)) {
		cout << "Vertex added" << endl;
	}
	else {
		cout << "Vertex not added" << endl; 
	}
	cout << "Only Node 5 in the graph" << endl;
	Graph1.display();								//only vertex 5 added
	cout << "---------------------" << endl << endl;		

	cout << "Adding array of Vertex" << endl;
	if (Graph1.addVertices(ArrayVertex, 3)) {		//Adding 3 vertex
		cout << "Vertex added" << endl;
	}
	else {
		cout << "Vertex not added" << endl;
	}
	Graph1.display();
	cout << "---------------------" << endl << endl;

	cout << "Removing Vertex with ID 3" << endl;
	if (Graph1.removeVertex(ArrayVertex[1])) {		//Removing Vertex with ID 3
		cout << "Vertex removed" << endl;
	}
	else {
		cout << "Does not exists" << endl;
	}
	Graph1.display();
	cout << "---------------------" << endl << endl;

	cout << "Removing Vertex with ID 1" << endl;
	if (Graph1.removeVertex(Node1)) {				//Removing a vertex not in the graph. Output false
		cout << "Vertex removed" << endl;
	}
	else {
		cout << "Does not exists" << endl;
	}
	Graph1.display();
	cout << "---------------------" << endl << endl;

	cout << "Adding Vertex 1 and 6" << endl;				//Adding Vertex 1 and 6
	Graph1.addVertex(Node1);
	Graph1.addVertex(Node6);
	Graph1.display();
	cout << "---------------------" << endl << endl;


	cout << "Adding all edges" << endl;
	if (Graph1.addEdge(Edge1)) {					//Adding Edge from Vertex 1 to 3 with a weight of 5
		cout << "Edge added" << endl;				//Vertex 3 does not exists. No endpoint. Edge will not be adeded
	}
		else {
			cout << "Edge not added" << endl;
		}
	if (Graph1.addEdge(Edge4)) {					//Adding Edge from Vertex 5 to 4 with a weight of 2
		cout << "Edge added" << endl;				//Vertex 3 does not exists, Edge will not be added
	}
		else {
			cout << "Edge not added" << endl;
		}
	if (Graph1.addEdge(Edge2)) {					//Adding Edge from Vertex 1 to 5 with a weight of 14
		cout << "Edge added" << endl;
	}
		else {
			cout << "Edge not added" << endl;
		}
	if (Graph1.addEdge(Edge3)) {					//Adding Edge from Vertex 3 to 2 with a weight of 9
		cout << "Edge added" << endl;				//Vertex 3 does not exists. No startpoint. Edge will not be added
	}
		else {
			cout << "Edge not added" << endl;
		}
	if (Graph1.addEdge(Edge5)) {					//Adding Edge from Vertex 6 to 2 with a weight of 19
		cout << "Edge added" << endl;				
	}
		else {
			cout << "Edge not added" << endl;
		}
	if (Graph1.addEdge(Edge4)) {					//Adding Link4 Again. Should not be added because it already exists.
		cout << "Edge added" << endl;
	}
	else {
		cout << "Edge not added" << endl;
	}
	Graph1.display();
	cout << "---------------------" << endl << endl;


	cout << "Removing Edge" << endl;				//Removing Edge#2 from 1 to 5
	Graph1.remove(Edge2);
	Graph1.display();
	cout << "---------------------" << endl << endl;

	cout << "Searching for Vertex 6" << endl;		//Search for Vertex 6 in the graph
	if (Graph1.searchVertex(Node6)) {
		cout << "Vertex is in the graph" << endl;
	}
	else {
		cout << "Vertex is not in the graph" << endl;
	}
	cout << "Searching for Vertex 3" << endl;			//Search for Vertex 3 in the graph
	if (Graph1.searchVertex(ArrayVertex[1])) {			// not in the graph
		cout << "Vertex is in the graph" << endl;	
	}
	else {
		cout << "Vertex is not in the graph" << endl;
	}
	Graph1.display();
	cout << "---------------------" << endl << endl;
	
	cout << "Searching for Edge 4" << endl;				//Search for Vertex 6 in the graph
	if (Graph1.searchEdge(Edge4)) {
		cout << "Edge is in the graph" << endl;
	}
	else {
		cout << "Edge is not in the graph" << endl;
	}
	cout << "Searching for Edge 2" << endl;				//Search for Vertex 3 in the graph
	if (Graph1.searchEdge(Edge2)) {						// not in the graph
		cout << "Edge is in the graph" << endl;
	}
	else {
		cout << "Edge is not in the graph" << endl;
	}
	Graph1.display();
	cout << "---------------------" << endl << endl;


	cout << "Calling toString funtion" << endl;			//prints all the edges
	cout << Graph1.toString() << endl;	
	cout << "---------------------" << endl << endl;

	cout << "Calling clean function" << endl;
	Graph1.clean();										//Removing all vertices and edges
	Graph1.display();

	cout << "---------------------" << endl << endl;
	cout << "---------------------" << endl << endl;
	cout << "---------------------" << endl << endl;
	cout << "---------------------" << endl << endl;

	cout << "OPERATOR OVERLOADING SECTION" << endl;

	DirectedGraph Graph2(ArrayVertex, 3);
	Graph2.addEdge(Edge3);
	Graph2.addEdge(Edge6);
	DirectedGraph Graph3;
	

	cout << "Graph2: " << endl;
	Graph2.display();								//graph2 has edges and vertices
	cout << "Graph3: " << endl;
	Graph3.display();								//graph3 is empty

	cout << "OVERLOADING operator=: Graph3 = Graph2" << endl;
	Graph3 = Graph2;								//graph3 get all the vertices and edges of graph2

	cout << "Graph2: " << endl;
	Graph2.display();
	cout << "Graph3: " << endl;
	Graph3.display();
	cout << "---------------------" << endl << endl;


	cout << "OVERLOADING operator==: Graph2 == Graph3" << endl;				//check if they have same vertices and edges
	if (Graph2 == Graph3) {
		cout << "Graph2 and Graph3 have the exact same vertices and edges" << endl;
	} 
	else {
		cout << "Graph are not equal" << endl;
	}
	cout << "---------------------" << endl << endl;

	cout << "OVERLOADING operator++: ++Graph2 and Graph2++ : Will be incremented by 2" << endl;						//Add 1 to the weight of each edges
	++Graph2;																				//Add 1 to the weight of each edges
	Graph2++;
	Graph2.display();
	cout << "---------------------" << endl << endl;

	cout << "OVERLOADING operator==: Graph2 == Graph3" << endl;				//graph should not be equal after increment ++
	if (Graph2 == Graph3) {
		cout << "Graph2 and Graph3 have the exact same vertices and edges" << endl;
	}
	else {
		cout << "Graph are not equal" << endl;		
	}
	cout << "---------------------" << endl << endl;

	cout << "OVERLOADING operator>: Graph2 > Graph3" << endl;			//graph should not be bigger after increment ++
	if (Graph2 > Graph3) {
		cout << "The sum of the weight of Graph2 is bigger than the sum of Graph3" << endl;
	}
	else {
		cout << "The sum of the weight of Graph2 is not bigger than the sum of Graph3" << endl;
	}
	cout << "---------------------" << endl << endl;

	cout << "OVERLOADING operator>: Graph3 > Graph2" << endl;			//graph should not be bigger after increment ++
	if (Graph3 > Graph2) {
		cout << "The sum of the weight of Graph3 is bigger than the sum of Graph2" << endl;
	}
	else {
		cout << "The sum of the weight of Graph3 is not bigger than the sum of Graph2" << endl;
	}
	cout << "---------------------" << endl << endl;


	DirectedGraph Graph4(ArrayVertex, 3);
	Graph4.addVertex(Node1);
	Graph4.addEdge(Edge1);
	Graph4.addEdge(Edge3);
	Graph4.addEdge(Edge6);
	cout << "Graph 4:" << endl;
	Graph4.display();

	DirectedGraph Graph5(Node5);
	Graph5.addVertex(Node6);
	Graph5.addEdge(Edge7);
	cout << "Graph 5:" << endl;
	Graph5.display();
	cout << "---------------------" << endl << endl;

	cout << "OVERLOADING operator+: Graph6 = Graph4 + Graph5" << endl;
	DirectedGraph Graph6;
	Graph6 = Graph4 + Graph5;
	cout << "Graph 6:" << endl;
	Graph6.display();
	cout << "---------------------" << endl << endl;

	cout << "OVERLOADING operator<<: cout << Graph6" << endl;
	cout << Graph6 << endl;
	return 0;
}