#pragma once
#include "VectorCompleteTree.h"

template<class E, template<class> class C>
class HeapPriorityQueue {
private:
	typedef typename VectorCompleteTree<E>::Position Position;
public:
	int size() const { return heap.size(); }
	bool empty() const { return heap.empty(); }
	void insert(const E&);
	const E& min() { return *(heap.getRoot()); }
	void removeMin();

	void append(HeapPriorityQueue<E, C>& hq) { 
		while (!hq.empty()) {
			insert(hq.min());
			hq.removeMin();
		}
	}
private:
	VectorCompleteTree<E> heap;
	C<E> isLess;
};

template<class E, template<class> class C>
void HeapPriorityQueue<E, C>::insert(const E& el) {
	heap.addLast(el);

	Position v = heap.getLast();

	while (!heap.isRoot(v)) {
		Position u = heap.parent(v);
		if (!isLess(*v, *u))
			break;

		heap.swap(v,u);

		v = u;
	}
} //bubble up

template<class E, template<class> class C>
void HeapPriorityQueue<E, C>::removeMin() {
	if (size() == 1)
		heap.removeLast();
	else {
		Position u = heap.getRoot();
		heap.swap(u, heap.getLast());
		heap.removeLast();

		while (heap.hasLeft(u)) {
			Position v = heap.left(u);

			if (heap.hasRight(u) && isLess(*(heap.right(u)), *v)) 
				v = heap.right(u);

			if (isLess(*v, *u)) {
				heap.swap(u, v);
				u = v;
			}
			else 
				break;
		}
	}

} //bubble down

template<typename E, template<class> class C>
HeapPriorityQueue<E, C>& heap_generateRand() {
	int numNodes, maxNumber;
	do {
		std::cout << "Please enter number of integers: ";
		std::cin >> numNodes;
	} while (numNodes <= 0);

	do {
		std::cout << "Please enter max number: ";
		std::cin >> maxNumber;
	} while (maxNumber <= 0);

	HeapPriorityQueue<E, C>* heap = new HeapPriorityQueue<E, C>();
	srand(time(0));

	/// Insert random values
	for (int i = 0; i < numNodes; i++) {
		heap->insert(1 + std::rand() % maxNumber);
	}

	return *heap;
}