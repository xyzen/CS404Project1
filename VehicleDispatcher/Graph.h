#pragma once
#include "Response.h"
#include "Edge.h"
#include "MinHeap.h"
#include <unordered_map>
#include <string>
#include <fstream>

class Graph
{
public:
	// Constructor takes file paths
	Graph(std::string edges_path, std::string vehicles_path);
	
	// Dispatches a vehicle if available and returns a response
	Response getResponse(Vehicle request);
private:
	// Structured members
	std::unordered_map<unsigned int, Node> vertices;
	MinHeap priority;

	void readEdges(std::string path);
	void addEdge(unsigned int from, unsigned int to, unsigned int weight);

	void readVehicles(std::string path);
	void addVehicle(unsigned int zip, unsigned int type, unsigned int ID);

	void expand(Node* next);
	void reset();

	Response dispatchResponse(Vehicle request, Vehicle responder, Node* origin);
};
