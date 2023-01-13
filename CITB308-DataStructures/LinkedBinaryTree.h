#pragma once
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include "Vector.h"

template<typename T>
class LinkedBinaryTree {
private:
	class Node {
	public:
		Node() : data(), parent(NULL), left(NULL), right(NULL) {}
		Node(const T& d) : data(d), parent(NULL), left(NULL), right(NULL) {}
	private:
		T data;
		Node* parent;
		Node* left;
		Node* right;

	friend class LinkedBinaryTree<T>;
	};
public:
	class Position {
	public:
		Position() : node(NULL) {}
		Position(Node* n) : node(n) {}

		T& operator*() { return node->data; }

		bool isInternal() const { 
			if (!node) {
				throw std::runtime_error("no node on this position");
			}
			return node->left || node->right; }
		bool isExternal() const { 
			if (!node) {
				throw std::runtime_error("no node on this position");
			}
			return !node->left && !node->right;
		}
		bool isRoot() const { 
			if (!node) {
				throw std::runtime_error("no node on this position");
			}
			return !node->parent;
		}

		Position parent() const {
			if (!node) {
				throw std::runtime_error("no node on this po sition");
			}
			return Position(node->parent);
		}
		Position left() const {
			if (!node) {
				throw std::runtime_error("no node on this position");
			}
			return Position(node->left);
		}
		Position right() const {
			if (!node) {
				throw std::runtime_error("no node on this position");
			}
			return Position(node->right);
		}
		T& getValue() const {
			if (!node) {
				throw std::runtime_error("Dereference null position");
			}
			return node->data;
		}

		void swapChildren() {
			if (isExternal()) return;
			Node* leftNode = node->left;
			node->left = node->right;
			node->right = leftNode;
		}
	private:
		Node* node;

	friend class LinkedBinaryTree<T>;
	};

public:
	LinkedBinaryTree() : root(new Node), sz(1) {}
	//LinkedBinaryTree(const LinkedBinaryTree&);
	//LinkedBinaryTree& operator=(const LinkedBinaryTree&);
	//~LinkedBinaryTree();

	int size() const { return sz; }
	bool empty() const { return sz == 0; }

	Position getRoot() const { return Position(root); }
	void setRoot(const T& data) { 
		if (root) {
			root->data = data;
		}
		else {
			root = new Node(data);
			sz++;
		}
	}

	//add child
	bool add(const Position& p, const T& data) {
		if (p.node->left && p.node->right) return false;

		if (p.isExternal()) expandExternal(p);
		if (p.node->left) setRight(p, data);
		else setLeft(p, data);
		return true;
	}
	void setLeft(const Position& p, const T& data) {
		if (p.node->left)
			p.node->left->data = data;
		else throw std::runtime_error("in order to add left node, you must expand first");
	}
	void setRight(const Position& p, const T& data) {
		if (p.node->right)
			p.node->right->data = data;
		else throw std::runtime_error("in order to add right node, you must expand first");
	}

	void expandExternal(const Position&);
	Position removeAboveExternal(const Position&); //remove pos and parent

	void print() const { print(root, 0); }
	void print(Node* n, int) const;
	void printEuler() const { eulerTour(root); }

	//height of children
	int height(const Position&) const;
	//depth from root
	int depth(const Position&) const;

	Vector<Position> positions() const;

	/* 
        void eulerTour(Node* node);
        Position preorderNext(const Position& pos);
        Position postorderNext(const Position& pos);*/
private:
	Node* root;
	int sz;
	void deleteTree(Node* n);
	void copy(const LinkedBinaryTree&);
	void preorder(Node*, Vector<Position>&) const;
	void postorder(Node*, Vector<Position>&) const;
	void eulerTour(Node*) const;
};

template<typename T>
std::ostream& operator<<(std::ostream& out, const LinkedBinaryTree<T>& t) {
	out << "Linked binary tree\n" << "size: " << t.size() << std::endl;
	t.print();
	Vector<LinkedBinaryTree<T>::Position> vec = t.positions();;
	Vector<T> printVec;

	for (int i = 0; i < vec.size(); i++){
		printVec.insert_back(*vec[i]);
	}

	out << printVec << "\n Euler tour:\n";
	t.printEuler();
	return out;
}

template<typename T>
void LinkedBinaryTree<T>::expandExternal(const Position& p) {
	if (p.isExternal()) {
		Node* n = p.node;
		n->left = new Node();
		n->left->parent = n;
		 
		n->right = new Node();
		n->right->parent = n;

		sz += 2;
	}
}

template<typename T>
typename LinkedBinaryTree<T>::Position LinkedBinaryTree<T>::removeAboveExternal(const Position& p) {
	if (p.isExternal()) {
		Node* n = p.node;
		Node* parent = n->parent;
		Node* sib = (n == parent->left ? parent->right : parent->left);

		if (parent == root) {
			//remove n and parent
			root = sib;
			sib->parent = NULL;
		}
		else {
			Node* v = parent->parent;
			if (v->left == parent)
				v->left = sib;
			else v->right = sib;

			sib->parent = v;
		}

		delete n, parent;
		sz -= 2;
		return Position(sib);
	}
	return NULL;
}

template<typename T>
void LinkedBinaryTree<T>::print(Node* n, int space) const {
	if (n) {
		print(n->right, space += 2);
		std::cout << std::setw(space) << n->data << std::endl;
		print(n->left, space);
	}
}

template<typename T>
int LinkedBinaryTree<T>::height(const Position& p) const {
	if (!p.node) return -1;
	else if (p.isExternal()) return 0;
	else return 1 + std::max(height(p.left()), height(p.right()));
}

template<typename T>
int LinkedBinaryTree<T>::depth(const Position& p) const {
	if (!p.node) return -1;
	else if (p.isRoot()) return 0;
	else return 1 + depth(p.parent());
}

template<typename T>
 Vector<typename LinkedBinaryTree<T>::Position> LinkedBinaryTree<T>::positions() const {
	 Vector<Position> vec;
	 preorder(root, vec);
	 return vec;
}

template<typename T>
void LinkedBinaryTree<T>::preorder(Node* n, Vector<Position>& vec) const {
	vec.insert_back(Position(n));

	if (n->left) {
		preorder(n->left, vec);
	}
	if (n->right) {
		preorder(n->right, vec);
	}
}

template<typename T>
void LinkedBinaryTree<T>::postorder(Node* n, Vector<Position>& vec) const {
	if (n->left) {
		postorder(n->left, vec);
	}
	if (n->right) {
		postorder(n->right, vec);
	}

	vec.insert_back(Position(n));
}

template<typename T>
void LinkedBinaryTree<T>::eulerTour(Node* node) const {
	Position pos(node);
	std::cout << *pos << std::endl;
	if (pos.node->left) {
		//TODO switch??
		eulerTour(pos.node->left);
		std::cout << *pos << std::endl;
	}
	if (pos.node->right) {
		eulerTour(pos.node->right);
		std::cout << *pos << std::endl;
	}
}

template <typename T>
void LinkedBinaryTree<T>::deleteTree(LinkedBinaryTree<T>::Node* node) {
	if (node) {
		deleteTree(node->left);
		deleteTree(node->right);
		delete node;
		node = nullptr;
		sz--;
	}
}

template<typename T>
LinkedBinaryTree<T>& binTree_generateRand() {
	int numNodes, maxNumber;
	do {
		std::cout << "Please enter number of integers: ";
		std::cin >> numNodes;
	} while (numNodes <= 0);

	do {
		std::cout << "Please enter max number: ";
		std::cin >> maxNumber;
	} while (maxNumber <= 0);

	LinkedBinaryTree<T>* lTree = new LinkedBinaryTree<T>();
	Vector<typename LinkedBinaryTree<T>::Position> pl = lTree->positions();

	lTree->setRoot(1 + std::rand() % maxNumber);

	for (int added = 0; added < numNodes - 1;)
	{
		if (lTree->add(pl.at(std::rand() % pl.size()), 1 + std::rand() % maxNumber)) 
		{
			pl = lTree->positions();
			added++;
		}
	}

	lTree->print();
	return *lTree;
}