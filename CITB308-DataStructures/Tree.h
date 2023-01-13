#pragma once
#include <iostream>
#include "Vector.h"

template<typename T>
class Tree {
private:
	struct Node {
		T data;
		Node* parent;
		Vector<Node*> children;
		Node() : data(NULL), parent(NULL) {};
	};
public:
	class Position {
	private:
		Node* node;
	public:
		Position() : node(NULL) {}
		Position(Node* v) : node(v) {}
		T& operator*() { return node->data; }
		Position parent() const { return Position(node->parent); }
		Vector<Node*> children() const { return Vector<Node*>(node->children); }
		bool isRoot() const { return node->parent == NULL; }
		bool isExternal() const { return node->children.isEmpty(); }
		
		friend class Tree;
	};

typedef Vector<Position> PositionList;      /// list of positions

public:
	Tree(const T& rootData = T()) { addRoot(rootData); }
	~Tree() { deleteTree(_root); }

	int size() const { return sz; }
	bool empty() const { return sz == 0; }
	
	Position root() const { return Position(_root); }
	
	void insert(const Position&, const T&);
	PositionList position() const;
	void print(const PositionList&) const;
	int depth(const Position&) const;

	/// TODO: depth()
protected:
	void addRoot(const T& rootData) { _root = new Node(); _root->data = rootData; sz = 1; }
	void preorder(Node*, PositionList&) const;
	void postorder(Node*, PositionList&) const;
private:
	Node* _root;
	int sz;
	void deleteTree(Node* v);
};

template<typename T>
std::ostream& operator<<(std::ostream& out, const Tree<T>& t) {
	out << "Tree's size: " << t.size() << " and continuing with vector's representation\n";
	
	typename Tree<T>::PositionList vec = t.position();
	Vector<T> printVec;

	for (int i = 0; i < vec.size(); i++) {
		printVec.insert_back(*vec[i]);
	}

	out << printVec << std::endl;

	t.print(vec);
	return out;
}

template<typename T>
void Tree<T>::insert(const Position& p, const T& data) {
	Node* parent = p.node;
	
	Node* n = new Node();
	n->data = data;
	n->parent = parent;
	parent->children.insert_back(n);

	sz++;

}//insert data after p

template<typename T>
typename Tree<T>::PositionList Tree<T>::position() const {
	PositionList vec;
	preorder(_root, vec);
	return vec;
}

template<typename T>
void Tree<T>::preorder(Node* n, PositionList& vec) const {
	vec.insert_back(Position(n));

	int chSize = n->children.size();
	for (int i = 0; i < chSize; i++)
	{
		Node* v = n->children.at(i);

		if (v != NULL)
			preorder(v, vec);
	}
}

template<typename T>
void Tree<T>::postorder(Node* n, PositionList& vec) const {
	int chSize = n->children.size();
	for (int i = 0; i < chSize; i++)
	{
		Node* v = n->children.at(i);

		if (v != NULL)
			postorder(v, vec);
	}

	/*int i = 0;
	while (i < n->children.size()) {
		Node* v = n->children.at(i);

		if (v != NULL) {
			postorder(v, vec);
		}

		i++;
	}*/

	vec.insert_back(Position(n));
}

template<typename T>
void Tree<T>::print(const PositionList& pList) const {
	for (int i = 0; i < pList.size(); i++)
	{
		Position p = pList.at(i);
		if (p.isRoot())
			std::cout << "Root: " << *p << std::endl;
		else {
			Position par = p.parent();
			std::cout << "Parent: " << *par << "\t" << "Child: " << *p;
		}

		std::cout << std::endl;
	}
}

template<typename T>
void Tree<T>::deleteTree(Node* v) {
	if (v != NULL) {
		int i = 0;
		while (i < v->children.size()) {
			deleteTree(v->children.at(i));
			v->children.remove(i);
		}

		v = NULL;
		delete v;
		sz--;
	}
}

template<typename T>
int Tree<T>::depth(const Position& p) const {
	if (p.isRoot()) return 0;
	return 1 + depth(p.parent());
}

template<typename T>
Tree<T>& tree_generateRand() {
	int numNodes, maxNumber;
	do {
		std::cout << "Please enter number of integers: ";
		std::cin >> numNodes;
	} while (numNodes <= 0);

	do {
		std::cout << "Please enter max number: ";
		std::cin >> maxNumber;
	} while (maxNumber <= 0);

	Tree<T>* t = new Tree<T>(1 + std::rand() % maxNumber);
	typename Tree<T>::PositionList pl = t->position();

	for (int i = 0; i < numNodes - 1; i++)
	{
		t->insert(pl.at(std::rand() % pl.size()), 1 + std::rand() % maxNumber);
		pl = t->position();
	}

	std::cout << *t << std::endl;

	return *t;
}

template<typename T>
int tree_getChildrenCount(const typename Tree<T>::Position& pos) {
	if (pos.isExternal())
		return 1;

	int count = 0;
	for (int i = 0; i < pos.children().size(); i++)
	{
		count += tree_getChildrenCount<T>(pos.children().at(i));
	}

	return 1 + count;
}