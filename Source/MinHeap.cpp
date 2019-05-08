#include "MinHeap.h"


bool MinHeap::empty() {
	return !heap.size();
} // True if heap is empty

// Inserts a Node to the end and reheaps it
void MinHeap::insert(Node* item) {
	// Add the item to the heap, update its index, and reheap
	item->heaped = true;
	heap.push_back(item);
	item->heap_index = heap.size() - 1;
	reheap(heap.size() - 1);
} // Returns nothing


// Reheaps a Node (toward the root) specified by heap index
void MinHeap::reheap(unsigned int index) {
	unsigned int child  = index, parent = (child - 1) / 2;
	while (child > 0 && heap[child]->cost < heap[parent]->cost) { 
		// Child's key is less than parent's key, so swap the Nodes
		std::swap(heap[parent]->heap_index, heap[child]->heap_index);
		std::swap(heap[parent], heap[child]);
		// Update relative variables
		child = parent;
		parent = (child - 1) / 2;
	}
} // Returns nothing

// Removes the lowest cost Node and returns it
Node* MinHeap::poptop() {
	// Save top of heap to return later
	Node* result = heap[0];
	// Move last Node to top of heap
	heap[0] = heap[heap.size() - 1];
	heap[0]->heap_index = 0;
	heap.pop_back();
	// Reheap the top Node downward
	unsigned int parent = 0, left = 1, right = 2;
	while (left < heap.size()) {
		// Parent Node has at least one child (left)
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
			else
				// Neither child's cost is lesser than the parent's; done
				break;
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
			// Neither child's cost is lesser than the parent's; done
			break;
	}
	return result;
} // Returns a reference to a Node with the minimum cumulative cost, buddy
