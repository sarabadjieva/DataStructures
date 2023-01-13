#pragma once
#include <iostream>

template <typename E, template<class> class C>
class PriorityQueue;

template<typename T>
class LexCompare {
public:
	bool operator()(const T& p1, const T& p2) const { return p1 < p2; }
};

template<typename E, template<class> class C>
PriorityQueue<E, C>& pQueue_generateRand() {
	int numNodes, maxNumber;
	do {
		std::cout << "Please enter number of integers: ";
		std::cin >> numNodes;
	} while (numNodes <= 0);

	do {
		std::cout << "Please enter max number: ";
		std::cin >> maxNumber;
	} while (maxNumber <= 0);

	PriorityQueue<E, C>* pQueue = new PriorityQueue<E, C>();
	srand(time(0));

	/// Insert random values
	for (int i = 0; i < numNodes; i++) {
		pQueue->insert(1 + std::rand() % maxNumber);
	}

	pQueue->print();
	return *pQueue;
}

template <typename E, template<class> class C>
NodeList<E>& PriorityQueueSort(NodeList<E>& L, PriorityQueue<E, C>& P) {
	while (!L.empty()) {
		E& e = *(L.begin());
		P.insert(e);
		L.remove_front();
	}

	while (!P.empty()) {
		E e = P.min();
		L.insert_back(e);
		P.removeMin();
	}

	return L;
}

template<class E, template<class> class C>
class PriorityQueue {
public:
	NodeList<E>* getList() const { return new NodeList<E>(L); }

	int size() const { return L.size(); }
	bool empty() const { return L.empty(); }
	
	void insert(const E&);
	
	E& min() const { return *(L.begin()); }
	void removeMin() { L.remove_front(); };
	void print() { std::cout << L; };
private:
	NodeList<E> L;
	C<E> isLess;
};

template<class E, template<class> class C>
std::ostream& operator<<(std::ostream& out, const PriorityQueue<E,C>& pQueue) {
	out << *(pQueue.getList());
	return out;
}

template<class E, template<class> class C>
void PriorityQueue<E, C>::insert(const E& el) {
	typename NodeList<E>::Iterator it = L.begin();

	while (it != L.end() && !isLess(el, *it)) {
		++it;
	}
	L.insert(it, el);
}