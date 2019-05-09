#pragma once
#include <vector>
#include "Node.h"

class MinHeap
{
public:
	// Heaping functions
	void insert(Node*);
	void reheap(unsigned int);
	Node* poptop();
	bool empty();
private:
	// Structured members
	std::vector<Node*> heap;
};
