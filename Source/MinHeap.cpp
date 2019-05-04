#include "MinHeap.h"

void MinHeap::insert(Node* item) {
	heap.push_back(item);
	heapify();
}


Node* MinHeap::poptop(Node*) {
	Node* result = heap[0];
	heap[0] = heap[heap.size() - 1];
	heap[0]->heap_index = 0;
	heap.pop_back();
	unsigned int
		parent = 0,
		left   = 1,
		right  = 2;
	while (left < heap.size()) {
		left  = 2 * parent + 1;
		right = 2 * parent + 2;
		if (right < heap.size())
		{
			if (heap[right]->weight < heap[left]->weight)
				std::swap(right, left);
			if (heap[left]->weight < heap[parent]->weight) {
				std::swap(heap[parent]->heap_index, heap[left]->heap_index);
				std::swap(heap[parent], heap[left]);
				parent = left;
			}
			else if (heap[right]->weight < heap[parent]->weight) {
				std::swap(heap[parent]->heap_index, heap[right]->heap_index);
				std::swap(heap[parent], heap[right]);
				parent = right;
			}
		}
		else if (heap[left]->weight < heap[parent]->weight)
		{
			std::swap(heap[parent]->heap_index, heap[left]->heap_index);
			std::swap(heap[parent], heap[left]);
			parent = left;
		}
		else
			break;
	}
	return result;
}

void MinHeap::heapify() {
	reheapify(heap.size() - 1);
}

void MinHeap::reheapify(unsigned int index) {
	unsigned int 
		child  = index,
		parent = child / 2;
	while (child && heap[child]->weight < heap[parent]->weight) {
		std::swap(heap[parent]->heap_index, heap[child]->heap_index);
		std::swap(heap[parent], heap[child]);
		parent /= 2;
	}
}