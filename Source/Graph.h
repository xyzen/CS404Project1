#pragma once
#include "Response.h"
#include "Request.h"
#include "Edge.h"
#include "MinHeap.h"
#include <unordered_map>
#include <string>
#include <fstream>

class Graph
{
public:
	Response getResponse(Request);
	Graph(std::string edges_path, std::string vehicles_path);
private:
	std::unordered_map<unsigned int, Node> vertices;
	MinHeap priority;

	Response createResponse(Vehicle, Node);
	void expand(Node);
	bool readEdges(std::string path);
	bool readVehicles(std::string path);
};
