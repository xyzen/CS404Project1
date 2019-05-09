#include "Graph.h"
#include <fstream>
#include <iostream>

int main() {
	// Initialize the graph
	Graph gr("Edges.txt", "Vehicle.txt");

	// File handling
	std::ifstream input;
	std::ofstream output;
	input.open("Request.txt"); output.open("Responses.txt");

	// Temp variables
	unsigned int reqID, type, zipcode;
	Vehicle rq;

	//Columns headers for the output file
	output << "Req ID" << "  " << "Req type" << " " << "Req zip" << "    " << "Vehicle ID" << " " << "Distence" << "     " << "Rout" << std::endl;

	// Get requests, process them, and output responses
	while (input >> reqID && input >> type && input >> zipcode) {
		// Create a request
		rq = Vehicle(zipcode, type, reqID);

		// Get a response
		Response r = gr.getResponse(rq);

		if (r.type)
			// Response type is not 0, so the request succeeded
			output << rq.ID << "\t" << rq.type << "\t" << rq.zip << "\t" << r.vehID << "\t" << r.dist << "\t" << r.route << std::endl;
		else
			// Response type is 0, so the request failed
			output << rq.ID << "\t" << rq.type << "\t" << rq.zip << "\tNo vehicle available" << std::endl;
	}
	return 0;
}
