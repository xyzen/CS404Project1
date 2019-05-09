#include "Vehicle.h"
#include "Graph.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
	Graph g("Edges.txt", "Vehicles.txt");
	unsigned int type, zip, id;
	ifstream input("Requests.txt");
	ofstream output("Responses.txt");
	while (input >> id && input >> type && input >> zip) {
		Vehicle rq = Vehicle(type, zip, id);
		Response r = g.getResponse(rq); //Response(reqID, request.type, request.zip, responder.ID, origin->cost, route);
		if (r.type) // 0 - no avaiable vehicle found 
			output << r.reqID << setw(2) << r.zip << setw(7) <<  r.type << setw(9) << r.id << setw(8) << r.dist << setw(5) << r.route << endl;// in the slide route is not given
		else
			output << r.zip << " " << rq.type << " " << "No vehicle available" << endl;
	}
}
