#include "Graph.h"
#include <fstream>
#include <iostream>

int main() {
	Graph gr("Edges.txt", "Vehicle.txt");
	std::ifstream input;
	std::ofstream output;
	input.open("Request.txt"); output.open("Responses.txt");
	unsigned int reqID, type, zipcode;
	Vehicle rq;
	while (input >> reqID && input >> type && input >> zipcode) {
		rq = Vehicle(zipcode, type, reqID);
		Response r = gr.getResponse(rq);
		if (r.type)
			output << rq.ID << "\t" << rq.type << "\t" << rq.zip << "\t" << r.vehID << "\t" << r.dist << "\t" << r.route << std::endl;
		else
			output << rq.ID << "\t" << rq.type << "\t" << rq.zip << "\tNo vehicle available" << std::endl;
	}
	return 0;
}
