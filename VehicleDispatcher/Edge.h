#pragma once
#include "Node.h"

struct Edge
{
	Edge(unsigned int from, unsigned int to, unsigned int weight);
	unsigned int from, to, weight;
};
