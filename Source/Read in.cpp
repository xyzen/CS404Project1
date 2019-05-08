#include <string>
#include <iostream>
#include <fstream>
#include "Node.h"
#include "Edge.h"
#include "Request.h"
#include <vector>
#include "Vehicle.h"

using namespace std;

void Build_Nodes(std::vector<Node*>& List) {
	// getting the nodes
	{
		ifstream inFile;

		inFile.open("Zipcodes_Vehicles.txt"); // to open the txt file
		if (!inFile) {
			cout << "File cannot be opened";
			exit(1); // exit, and stop because the file cannot be find or opened.
		}

		int zipCode;
		int numOfAdj;
		int adjZipCode;
		int adjWeight;
		int vehID;
		int vehType;


		while (inFile) { // read the file
			inFile >> zipCode;
			inFile >> numOfAdj;
			Node* parent = new Node(zipCode);   //sets the starting node
			for (int i = 0; i < numOfAdj; i++)
			{

				inFile >> adjZipCode;
				inFile >> adjWeight;
				Node* node = new Node(adjZipCode);  //creats another node
				parent->addAdjacency(node, adjWeight); // adds it adjecent to the starting node
			}
			inFile >> vehID;
			inFile >> vehType;
			Vehicle* veh = new Vehicle(vehID, vehType, zipCode);
			parent->addVehicle(veh);
			List.push_back(parent);


		}

		inFile.close();
	}
	// adding the vehicles to the nodes
	
}
void Build_Request(Request &req)
{
	ifstream inFile;

	inFile.open("Request.txt"); // to open the txt file
	if (!inFile) {
		cout << "File cannot be opened";
		exit(1); // exit, and stop because the file cannot be find or opened.
	}

	int reqId;
	int reqType;
	int reqZip;

	inFile >> reqId;
	inFile >> reqType;
	inFile >> reqZip;

	req.setID(reqId);
	req.setType(reqType);
	req.setZipCode(reqZip);

	inFile.close();
}

int main()
{
	std::vector<Node*> List;
	Request req;
	Build_Nodes(List);
	Build_Request(req);
	
	return 0;
}

/*
txt file layout
zipcodes - zip, num of adj, adjZips, vehicle id, vehicle type
Request - Req id, req type, req zip
*/