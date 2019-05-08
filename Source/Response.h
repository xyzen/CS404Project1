#pragma once
#include <string>

struct Response
{
	Response(unsigned int type, unsigned int zip, unsigned int id, unsigned int dist, std::string route);
	unsigned int type, zip, id, dist;
	std::string route;
};
