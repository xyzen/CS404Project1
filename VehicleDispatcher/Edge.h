#pragma once
#include "Node.h"

struct Edge
{
	// Constructor
	Edge(unsigned int from, unsigned int to, unsigned int weight);

	// Primative members
	unsigned int from, to, weight;
};
