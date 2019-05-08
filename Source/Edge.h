#pragma once
#include "Node.h"

struct Edge
{
<<<<<<< HEAD
	Edge(unsigned int from, unsigned int to, unsigned int weight);
=======
public:
	Edge();
	Edge(const Node& Node1, const Node& Node2, unsigned int weight);
>>>>>>> 72501ab31fd7c069f3f2b6ce6116f84a042e94c3
	unsigned int from, to, weight;
};
