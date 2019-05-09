#include "Graph.h"
#include <fstream>
#include <iostream>

int main() {
	Graph gr("edges.txt", "vehicles.txt");
	std::fstream input("requests.txt"), output("responses.txt");
	unsigned int reqID, type, zipcode;
	Vehicle rq;
	while (input.good()) {
		input >> type;
		input >> zipcode;
		rq = Vehicle(zipcode, type, reqID);
		Response r = gr.getResponse(rq);
		if (r.type)
			output << rq.ID << "\t" << rq.type << "\t" << rq.zip << "\t" << r.vehID << "\t" << r.route << std::endl;
		else
			output << rq.ID << "\t" << rq.type << "\t" << rq.zip << "\tNo vehicle available" << std::endl;

	}
	return 0;
}
