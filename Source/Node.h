#pragma once
#include <vector>
#include "Vehicle.h"

class Node
{
public:
	Node(unsigned int zip);
	void addAdjacency(Node* next, unsigned int cost);
	void addVehicle(Vehicle* VehType);
	unsigned int cost, predecessor, zipcode;
	int heap_index = -1;
	bool visited = false;
	std::vector<Node*> adjacent;
	std::vector<Vehicle*> vehicles;
	std::vector<unsigned int> weights;
};
