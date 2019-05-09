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
	std::queue<Vehicle> type1_vehicles, type2_vehicles, type3_vehicles;
	std::vector<Node*> adjacencies;
	std::vector<unsigned int> weights;
	
	// Graph-building methods
	void addAdjacency(Node* next, unsigned int weight);
	void addVehicle(unsigned int zip, unsigned int type, unsigned int ID);
	void reset();

	// Dispatch methods
	bool satisfies(unsigned int type);
	Vehicle popVehicle(unsigned int type);
};
