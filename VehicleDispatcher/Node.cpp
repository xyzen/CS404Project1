#include "Node.h"


Node::Node() {
	zipcode = 0;
	cost = std::numeric_limits<unsigned int>::max();
	heaped = false;
	visited = false;
	predecessor = nullptr;
} // Constructs default Node


Node::Node(unsigned int zip) {
	zipcode = zip;
	cost = std::numeric_limits<unsigned int>::max();
	heaped = false;
	visited = false;
	predecessor = nullptr;
} // Constructs Node based on arguments


void Node::addAdjacency(Node* next, unsigned int weight) {
	adjacencies.push_back(next);
	weights.push_back(weight);
} // Adds an adjacency to the Node


void Node::addVehicle(unsigned int zip, unsigned int type, unsigned int ID) {
	switch (type) {
	case(1):
		ready1_vehicles.push(Vehicle(zip, type, ID));
		break;
	case(2):
		ready2_vehicles.push(Vehicle(zip, type, ID));
		break;
	case(3):
		ready3_vehicles.push(Vehicle(zip, type, ID));
		break;
	default:
		break;
	}
} // Adds a vehicle to the Node based on type\


void Node::addBusyVehicle(Vehicle responder) {
	switch (responder.type) {
	case(1):
		busy1_vehicles.push(responder);
		break;
	case(2):
		busy2_vehicles.push(responder);
		break;
	case(3):
		busy3_vehicles.push(responder);
		break;
	default:
		break;
	}
} // Adds a busy vehicle to the Node based on type


bool Node::satisfies(unsigned int type) {
	switch (type) {
	case(1):
		return ready1_vehicles.size();
	case(2):
		return ready2_vehicles.size();
	case(3):
		return ready3_vehicles.size();
	default:
		return false;
	}
} // Returns true of vehicle type is available


Vehicle Node::popVehicle(unsigned int type) {
	Vehicle result;
	switch (type) {
	case(1):
		result = ready1_vehicles.front();
		ready1_vehicles.pop();
		return result;
	case(2):
		result = ready2_vehicles.front();
		ready2_vehicles.pop();
		return result;
	case(3):
		result = ready3_vehicles.front();
		ready3_vehicles.pop();
		return result;
	default:
		return result;
	}
} // Pops and returns the requested vehicle

void Node::reset() {
	cost = std::numeric_limits<unsigned int>::max();
	heaped = false;
	visited = false;
	predecessor = nullptr;
} // Resets Node for next search


void Node::resetVehicles() {
	while (busy1_vehicles.size()) {
		ready1_vehicles.push(busy1_vehicles.front());
		busy1_vehicles.pop();
	}
	while (busy2_vehicles.size()) {
		ready2_vehicles.push(busy2_vehicles.front());
		busy2_vehicles.pop();
	}
	while (busy3_vehicles.size()) {
		ready3_vehicles.push(busy3_vehicles.front());
		busy3_vehicles.pop();
	}
} // Moves all Vehicles from busy to ready
