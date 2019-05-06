#pragma once
#include <vector>
#include "Node.h"

class MinHeap
{
public:
	void insert(Node*);
	Node* poptop(Node*);
private:
	std::vector<Node*> heap;
	void reheapify(unsigned int);
	void heapify();
};
