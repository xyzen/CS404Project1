#include "Graph.h"

// Constructor
Graph::Graph(std::string edges_path, std::string vehicles_path) {
	readEdges(edges_path);
	readVehicles(vehicles_path);
} // Reads edges and vehicles from files


void Graph::readEdges(std::string path) {
	// File handler
	std::ifstream file(path);

	// Temp variables
	unsigned int from, to, weight;
	while (file.good()) {
		// Get data from file
		file >> from;
		file >> to;
		file >> weight;
		// Initialize adjacency
		addEdge(to, from, weight);
	}
} // Updates Node adjacencies from file


void Graph::addEdge(unsigned int from, unsigned int to, unsigned int weight) {
	// Ensure both Nodes are present in the graph
	if (!vertices.count(from))
		vertices[from] = Node(from);
	if (!vertices.count(to))
		vertices[to] = Node(to);

	// Initialize adjacency
	vertices[from].addAdjacency(&vertices[to], weight);
} // Adds an adjacency to the graph


void Graph::readVehicles(std::string path) {
	// File handler
	std::ifstream file(path);

	// Temp variables
	unsigned int zip, type, ID;
	while (file.good()) {
		// Read in data
		file >> ID;
		file >> type;
		file >> zip;

		// Initialize vehicle
		addVehicle(zip, type, ID);
	}
} // Updates Node vehicles from file



void Graph::addVehicle(unsigned int zip, unsigned int type, unsigned int ID) {
	// Ensure node is present in graph
	if (!vertices.count(zip))
		vertices[zip] = Node(zip);

	// Initialize vehicle
	vertices[zip].addVehicle(zip, type, ID);
} // Adds a vehicle to the graph

// Graph searching
void Graph::expand(Node* parent) {
	// Visit the parent
	parent->visited = true;

	// Visit adjacencies and add them to priority queue (MinHeap)
	for (unsigned int i = 0; i < parent->adjacencies.size(); i++) {
		// Get adjacent Node
		Node* child = parent->adjacencies[i];

		// Don't recheck visited Nodes
		if (child->visited)
			continue;

		// Get new cumulative cost
		unsigned int new_cost = parent->cost + parent->weights[i];

		if (child->heaped) {
			// Child is already in the heap
			if (new_cost < child->cost) {
				// Lower cost found: update cost of child and reheap
				child->cost = new_cost;
				child->predecessor = parent;
				priority.reheap(child->heap_index);
			}
		}
		else {
			// Child has not been visited or heaped: add it to heap
			child->cost = new_cost;
			child->predecessor = parent;
			priority.insert(child);
		}
	}
} // Adds all adjacent Nodes to the heap with cumulative cost as key


Response Graph::getResponse(Vehicle request) {
	unsigned int type = request.type, zip = request.zip;

	// Get the source Node
	Node *source = &vertices[zip], *next;

	// Prepare it for search
	source->predecessor = nullptr;
	source->cost = 0;
	priority.insert(source);

	while (!priority.empty()) {
		// Node is present in priority queue
		next = priority.poptop();

		// If vehicle found, return response
		if (next->satisfies(type)) {
			Vehicle responder = next->popVehicle(type);
			source->addBusyVehicle(responder);
			return dispatchResponse(request, responder, next);
		}

		// Vehicle not found: expand Node
		expand(next);
	}
	// Failure! Reset the graph and return default Response
	reset();
	return Response(0,0,0,0,0,"");
} // Returns best Response to the request: default if request failed


Response Graph::dispatchResponse(Vehicle request, Vehicle responder, Node* origin) {
	// Get starting point of responding vehicle
	Node* next = origin;

	// Reconstruct its path to the source Node
	std::string route = std::to_string(origin->zipcode);
	while (next->predecessor != nullptr) {
		// Add each predecessor to the route until source found
		next = next->predecessor;
		route += "->" + std::to_string(next->zipcode);
	}
	// Constuct new response
	Response r(request.ID, request.type, request.zip, responder.ID, origin->cost, route);

	// Reset graph for next search and return Response
	reset();
	return r;
} // Returns a Response to a successful request


void Graph::reset() {
	std::unordered_map<unsigned int, Node>::iterator i;
	for (i = vertices.begin(); i != vertices.end(); ++i) {
		// Reset each Node in the Graph
		i->second.reset();
	}
} // Resets the graph for the next search


void Graph::resetVehicles() {
	std::unordered_map<unsigned int, Node>::iterator i;
	for (i = vertices.begin(); i != vertices.end(); ++i) {
		// Reset Vehicles for each Node in the Graph
		i->second.resetVehicles();
	}
} // Moves Vehicles in all Nodes from busy to ready
