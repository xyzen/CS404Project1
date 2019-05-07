#include "MinHeap.h"

// Insert a Node into the heap
void MinHeap::insert(Node* item) {
	// Keep track of heap index
	item->heap_index = heap.size() - 1;
	// Add the item to the heap, and reheap
	heap.push_back(item);
	heapify();
} // Returns nothing

// Remove the lowest cost Node and return it
Node* MinHeap::poptop() {
	// Save top of heap to return later
	Node* result = heap[0];
	// Move last Node to top of heap
	heap[0] = heap[heap.size() - 1];
	heap[0]->heap_index = 0;
	heap.pop_back();
	// Reheap the top Node
	unsigned int parent = 0, left = 1, right = 2;
	while (left < heap.size()) {
		// Parent node has at least one child (left)
		if (right < heap.size()) {
			// Parent Node has two children (left and right)
			if (heap[right]->cost < heap[left]->cost) {
				// Ensure left is min child
				std::swap(right, left);
			}
			if (heap[left]->cost < heap[parent]->cost) {
				// Min child's key is less than parent's key, so swap the Nodes
				std::swap(heap[parent]->heap_index, heap[left]->heap_index);
				std::swap(heap[parent], heap[left]);
				// Update relative variables
				parent = left;
				left = (2 * parent) + 1;
				right = (2 * parent) + 2;
			}
			else if (heap[right]->cost < heap[parent]->cost) {
				// Max child's key is less than parent's key, so swap the Nodes
				std::swap(heap[parent]->heap_index, heap[right]->heap_index);
				std::swap(heap[parent], heap[right]);
				// Update relative variables
				parent = right;
				left = (2 * parent) + 1;
				right = (2 * parent) + 2;
			}
		}
		else if (heap[left]->cost < heap[parent]->cost) {
			// Parent has only one child and its key is lesser, so swap them
			std::swap(heap[parent]->heap_index, heap[left]->heap_index);
			std::swap(heap[parent], heap[left]);
			// Update relative variables
			parent = left;
			left = (2 * parent) + 1;
			right = (2 * parent) + 2;
		}
		else
			// Neither child is less 
			break;
	}
	return result;
}

void MinHeap::heapify() {
	// Reheap the very last Node
	reheapify(heap.size() - 1);
}

// Reheap a Node by index specific index
void MinHeap::reheapify(unsigned int index) {
	unsigned int child  = index, parent = child / 2;
	while (parent && heap[child]->cost < heap[parent]->cost) { 
		// Child's key is less than parent's key, so swap the Nodes
		std::swap(heap[parent]->heap_index, heap[child]->heap_index);
		std::swap(heap[parent], heap[child]);
		// Update relative variables
		child = parent;
		parent /= 2;
	}
}
