#include "Graph.h"

Graph::Graph(std::string edges_path, std::string vehicles_path) {
	readEdges(edges_path);
	readEdges(vehicles_path);
}


bool Graph::readEdges(std::string path) {
	std::ifstream file(path);
	if (file.fail())
		return false;
	unsigned int from, to, weight;
	while (file.good()){

	}
	

		
}


/*
Response Graph::getResponse(Request) {
	 
}


Response Graph::createResponse(Vehicle, Node) {
	
}


void Graph::expand(Node) {
	
}
*/