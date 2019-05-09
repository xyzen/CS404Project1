#pragma once
#include <string>

struct Response
{
	// Constructor
	Response(unsigned int reqID, unsigned int type, unsigned int zip, unsigned int id, unsigned int dist, std::string route);

	// Data members
	unsigned int reqID, type, zip, vehID, dist;
	std::string route;
};
