#pragma once
#include <vector>

template<typename T>
class VectorCompleteTree {
public:
	typedef typename std::vector<T>::iterator Position;
public:
	VectorCompleteTree() : vec() {}

	int size() const { return vec.size(); }
	bool empty() const { return vec.empty(); }

	Position getRoot() { if ((!empty())) return pos(1); return vec.end(); }
	Position getLast() { if ((!empty()))return pos(size() - 1); return vec.end(); }

	Position left(const Position& p) { return pos(2 * idx(p)); }
	Position right(const Position& p) { return pos(2 * idx(p) + 1); }
	Position parent(const Position& p) { return pos(idx(p) / 2); }

	bool hasLeft(const Position& p) const { return 2*idx(p)< size(); } //f(left) = 2f(parent)
	bool hasRight(const Position& p) const { return 2 * idx(p) + 1 < size(); }; //f(left) = 2f(parent) + 1
	bool isRoot(const Position& p) const { return idx(p) == 1; };

	void addLast(const T& el) { vec.push_back(el); }
	void removeLast() { vec.pop_back(); }

	void swap(const Position& p1, const Position& p2)
	{ 
		T el = *p2; *p2 = *p1; *p1 = el; 
	}

protected:
	Position pos(int i) { return vec.begin() + i; }
	int idx(const Position& pos) const { return pos - vec.begin(); }
private:
	std::vector<T> vec;
};