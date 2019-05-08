#include "Node.h"

Node::Node(unsigned int zip) {
	zipcode = zip;
}

void Node::addAdjacency(Node* next, unsigned int cost) {
	adjacent.push_back(next);
	weights.push_back(cost);
}
void Node::addVehicle(Vehicle* nVehicle)
{
	vehicles.push_back(nVehicle);

}
