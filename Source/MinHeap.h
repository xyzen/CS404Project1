#pragma once
#include <vector>
#include "Node.h"

class MinHeap
{
public:
	void insert(Node*);
	void reheap(unsigned int);
	Node* poptop();
	bool empty();
private:
	std::vector<Node*> heap;
};
