#pragma once
#include "Node.h"

class Edge
{
public:
	Edge();
	Edge(const Node& Node1, const Node& Node2, unsigned int weight);
	unsigned int from, to, weight;
};

