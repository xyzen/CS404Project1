#include "Node.h"


Node::Node() {
	zipcode = 0;
	cost = std::numeric_limits<unsigned int>::max();
	heaped = false;
	visited = false;
	predecessor = nullptr;
}


Node::Node(unsigned int zip) {
	zipcode = zip;
	cost = std::numeric_limits<unsigned int>::max();
	heaped = false;
	visited = false;
	predecessor = nullptr;
}


void Node::addAdjacency(Node* next, unsigned int weight) {
	adjacencies.push_back(next);
	weights.push_back(weight);
}


void Node::addVehicle(unsigned int zip, unsigned int type, unsigned int ID) {
	switch (type) {
	case(1):
		type1_vehicles.push(Vehicle(zip, type, ID));
		break;
	case(2):
		type2_vehicles.push(Vehicle(zip, type, ID));
		break;
	case(3):
		type3_vehicles.push(Vehicle(zip, type, ID));
		break;
	default:
		break;
	}
}


bool Node::satisfies(unsigned int type) {
	switch (type) {
	case(1):
		return type1_vehicles.size();
	case(2):
		return type2_vehicles.size();
	case(3):
		return type3_vehicles.size();
	default:
		return false;
	}
}


Vehicle Node::popVehicle(unsigned int type) {
	Vehicle result;
	switch (type) {
	case(1):
		result = type1_vehicles.front();
		type1_vehicles.pop();
		return result;
	case(2):
		result = type2_vehicles.front();
		type2_vehicles.pop();
		return result;
	case(3):
		result = type3_vehicles.front();
		type3_vehicles.pop();
		return result;
	default:
		return result;
	}
}

void Node::reset() {
	cost = std::numeric_limits<unsigned int>::max();
	heaped = false;
	visited = false;
	predecessor = nullptr;
}
