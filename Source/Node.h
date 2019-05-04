#pragma once
#include <list>
class Node
{
public:
	Node();
	~Node();
	unsigned int weight;
	unsigned int predecessor;
	unsigned int heap_index = -1;
	unsigned int zipcode_index;
	unsigned int zipcode;
	bool visited = false;

};

