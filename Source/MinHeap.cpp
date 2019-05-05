#include "MinHeap.h"

void MinHeap::insert(Node* item) {
	item->heap_index = heap.size - 1;
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
			if (heap[right]->cost < heap[left]->cost)
				std::swap(right, left);
			if (heap[left]->cost < heap[parent]->cost) {
				std::swap(heap[parent]->heap_index, heap[left]->heap_index);
				std::swap(heap[parent], heap[left]);
				parent = left;
			}
			else if (heap[right]->cost < heap[parent]->cost) {
				std::swap(heap[parent]->heap_index, heap[right]->heap_index);
				std::swap(heap[parent], heap[right]);
				parent = right;
			}
		}
		else if (heap[left]->cost < heap[parent]->cost)
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
	while (child && heap[child]->cost < heap[parent]->cost) {
		std::swap(heap[parent]->heap_index, heap[child]->heap_index);
		std::swap(heap[parent], heap[child]);
		parent /= 2;
	}
}