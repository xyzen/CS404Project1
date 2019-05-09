#include "Graph.h"

Graph::Graph(std::string edges_path, std::string vehicles_path) {
	readEdges(edges_path);
	readVehicles(vehicles_path);
}


void Graph::readEdges(std::string path) {
	std::ifstream file(path);
	unsigned int from, to, weight;
	while (file.good()) {
		file >> from;
		file >> to;
		file >> weight;
		addEdge(to, from, weight);
	}
}


void Graph::addEdge(unsigned int from, unsigned int to, unsigned int weight) {
	if (!vertices.count(from))
		vertices[from] = Node(from);
	if (!vertices.count(to))
		vertices[to] = Node(to);
	vertices[from].addAdjacency(&vertices[to], weight);
}


void Graph::readVehicles(std::string path) {
	std::ifstream file(path);
	unsigned int zip, type, ID;
	while (file.good()) {
		file >> ID;
		file >> type;
		file >> zip;
		addVehicle(zip, type, ID);
	}
}



void Graph::addVehicle(unsigned int zip, unsigned int type, unsigned int ID) {
	if (!vertices.count(zip))
		vertices[zip] = Node(zip);
	vertices[zip].addVehicle(zip, type, ID);
}


void Graph::expand(Node* parent) {
	parent->visited = true;
	for (unsigned int i = 0; i < parent->adjacencies.size(); i++) {
		Node* child = parent->adjacencies[i];
		if (child->visited)
			continue;
		unsigned int new_cost = parent->cost + parent->weights[i];
		if (child->heaped) {
			if (new_cost < child->cost) {
				child->cost = new_cost;
				child->predecessor = parent;
				priority.reheap(child->heap_index);
			}
		}
		else {
			child->cost = new_cost;
			child->predecessor = parent;
			priority.insert(child);
		}
	}
}


Response Graph::getResponse(Vehicle request) {
	unsigned int type = request.type, zip = request.zip;
	Node *source = &vertices[zip], *next;
	source->predecessor = nullptr;
	source->cost = 0;
	priority.insert(source);
	while (!priority.empty()) {
		next = priority.poptop();
		if (next->satisfies(type))
			return dispatchResponse(request, next->popVehicle(type), next);
		expand(next);
	}
	reset();
	return Response(0,0,0,0,0,"");
}


Response Graph::dispatchResponse(Vehicle request, Vehicle responder, Node* origin) {
	Node* next = origin;
	std::string route = std::to_string(origin->zipcode);
	while (next->predecessor != nullptr) {
		next = next->predecessor;
		route += "->" + std::to_string(next->zipcode);
	}
	Response r(request.ID, request.type, request.zip, responder.ID, origin->cost, route);
	reset();
	return r;
}


void Graph::reset() {
	std::unordered_map<unsigned int, Node>::iterator i;
	for (i = vertices.begin(); i != vertices.end(); ++i) {
		i->second.reset();
	}
}
