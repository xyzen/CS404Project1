#pragma once
#include <vector>
#include <queue>
#include "Vehicle.h"

struct Node
{
	// Constructor
	Node();
	Node(unsigned int zip);

	// Primative members
	unsigned int cost, zipcode, heap_index;
	bool heaped, visited;

	// Structured members
	Node* predecessor;
	std::queue<Vehicle> ready1_vehicles, ready2_vehicles, ready3_vehicles, busy1_vehicles, busy2_vehicles, busy3_vehicles;
	std::vector<Node*> adjacencies;
	std::vector<unsigned int> weights;
	
	// Graph-related methods
	void addAdjacency(Node* next, unsigned int weight);
	void addVehicle(unsigned int zip, unsigned int type, unsigned int ID);
	void addBusyVehicle(Vehicle responder);
	void reset();
	void resetVehicles();

	// Dispatch methods
	bool satisfies(unsigned int type);
	Vehicle popVehicle(unsigned int type);
};
