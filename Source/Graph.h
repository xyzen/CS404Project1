#pragma once
#include <vector>
#include "Node.h"

class Graph
{
public:
	Graph();
	~Graph();
private:
	std::vector<Node> vertices;

};

